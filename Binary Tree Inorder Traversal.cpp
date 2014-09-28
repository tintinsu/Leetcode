#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
* Definition for binary tree
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// sol_1: recursive solution
	// Time O(n), Space O(n)
	vector<int> vec;
	vector<int> inorderTraversal_1(TreeNode *root) {
		vec.clear();
		inorder_recursive(root);
		return vec;
	}
	void inorder_recursive(TreeNode *node) {
		if(!node) return;
		inorder_recursive(node->left);
		vec.push_back(node->val);
		inorder_recursive(node->right);
	}


	/* sol_2: iterative stack + last node
	* Time O(n), Space O(n)
	* Comment: TLE & MLE 
	* Mistake: flatten the tree, the last is always the right-most of left subtree, 
	* instead of the left child.This "last" setting fits post order traversal!!!
	*/
	vector<int> inorderTraversal_2_mistake(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode *> sta; 
		if(!root) return ret;
		sta.push(root);
		TreeNode *last = NULL;

		// inorder traversal
		while(!sta.empty()) {
			TreeNode *top = sta.top();

			if(!top->left || top->left==last){
				// cannot go left
				sta.pop();
				ret.push_back(top->val);
				if(top->right) sta.push(top->right);
			}else{
				// continue going left
				sta.push(top->left);
			}

			// update last
			last = top;
		}

		// return
		return ret;
	}


	/* sol_2-1: iterative stack + direction
	* Time O(n), Space O(n)
	*/
	vector<int> inorderTraversal_2_1(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode *> sta; 
		if(!root) return ret;
		sta.push(root);
		bool down = true;

		// inorder traversal
		while(!sta.empty()) {
			TreeNode *top = sta.top();

			if(down){
				if(top->left){sta.push(top->left); continue;}
				down=false;
			}else{
				sta.pop();
				ret.push_back(top->val);
				if(top->right){sta.push(top->right); down=true;}
			}
		}

		// return
		return ret;
	}

	/* sol_2-2: iterative stack + curr
	* Time O(n), Space O(n)
	* Idea: in order traversal - record a node if the previous is null
	*/
	vector<int> inorderTraversal_2_2(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		TreeNode *curr = root;
		stack<TreeNode *> sta;

		// iterative: stack + curr
		while(curr || !sta.empty()){
			if(curr){
				sta.push(curr);
				curr = curr->left;
			}else if(!sta.empty()){
				ret.push_back(sta.top()->val);
				curr=sta.top()->right;
				sta.pop();
			}
		}

		// return
		return ret;
	}

	/* sol_3: iterative
	* Time O(n) Space O(1)
	*/
	vector<int> inorderTraversal(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		TreeNode *curr = root;

		// iteration
		while(curr){
			if(curr->left){
				// find the right-most from the left subtree
				TreeNode *prev = curr->left;
				while(prev->right && prev->right!=curr) prev = prev->right;
				if(prev->right == curr){
					ret.push_back(curr->val);
					curr = curr->right;
					prev->right = NULL;
				}else{
					prev->right = curr;
					curr = curr->left;
				}
			}else{
				ret.push_back(curr->val);
				curr = curr->right;
			}
		}

		// return
		return ret;
	}

};

int main()
{
	// construct a tree
	TreeNode *n1 = new TreeNode(3);
	TreeNode *n2 = new TreeNode(1);
	TreeNode *n3 = new TreeNode(2);
	n1->left = n2; n1->right = n3;

	// solution
	Solution sol;
	vector<int> val = sol.inorderTraversal_2_2(n1);
	for(int i=0;i<val.size();i++) cout<<val[i]<<" ";
	cout<<endl;
	system("pause");
	return 1;
}