#include<iostream>
#include<vector>
#include<algorithm>
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
	/* sol_1: recursive
	* Comments: Memory Limit Exceeded
	* Reason: create too many vectors
	*/
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.size() == 0) return NULL;

		// create a node
		TreeNode *node = new TreeNode(preorder[0]);

		// find left + right subtrees
		int i;
		for(i=0;i<inorder.size();i++){
			if(inorder[i] == node->val) break;
		}
		int nLeft=i; 
		int nRight=inorder.size()-1-nLeft;

		// construct subtrees
		if(nLeft != 0){
			vector<int> preorder1(preorder.begin()+1, preorder.begin()+1+nLeft);
			vector<int> inorder1(inorder.begin(), inorder.begin()+nLeft);
			node->left = buildTree(preorder1, inorder1);
		}

		if(nRight != 0){
			vector<int> preorder2(preorder.begin()+nLeft+1, preorder.end());
			vector<int> inorder2(inorder.begin()+nLeft+1, inorder.end());
			node->right = buildTree(preorder2, inorder2);
		}

		// return
		return node;
	}

	/* sol_2: recursive
	*/
	vector<int> preorder, inorder;
	TreeNode *buildTree_2(vector<int> &preorder_1, vector<int> &inorder_1) {
		preorder = preorder_1;
		inorder = inorder_1;
		int pre_0=0, pre_1=preorder.size()-1;
		int in_0=0, in_1=pre_1;
		return buildTree(pre_0,pre_1,in_0,in_1);
	}

	TreeNode *buildTree(int pre_0,int pre_1,int in_0,int in_1){
		// special case
		if(pre_0>pre_1) return NULL;

		// create a node
		TreeNode *node = new TreeNode(preorder[pre_0]);

		// boundary computation
		vector<int>::iterator it=find(inorder.begin()+in_0, inorder.begin()+in_1+1, node->val);
		int idx = it - inorder.begin();
		int nLeft = idx-in_0;

		// subtree assignment
		node->left = buildTree(pre_0+1, pre_0+nLeft, in_0, in_0+nLeft-1);
		node->right = buildTree(pre_0+nLeft+1, pre_1, in_0+nLeft+1, in_1);

		// return
		return node;
	}
};

void print_tree(TreeNode *node){
	if(!node) return;
	cout << node->val << " ";
	print_tree(node->left);
	print_tree(node->right);
}

int main()
{
	// construct inputs
	int arr_preorder[3]={1,2,3};
	vector<int> preorder; preorder.assign(arr_preorder, arr_preorder+3);
	int arr_inorder[3] = {3,2,1};
	vector<int> inorder; inorder.assign(arr_inorder, arr_inorder+3);

	// run the algorithm
	Solution sol;
	TreeNode* root = sol.buildTree(preorder, inorder);

	// print the tree
	print_tree(root);
	system("pause");
	return 1;
}