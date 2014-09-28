/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	/* sol_1: recusive method
	* Time O(n), Space O(n)
	*/
	vector<int> ret;
	vector<int> postorderTraversal(TreeNode *root) {
		ret.clear();
		postorder_recursive(root);
		return ret;
	}
	void postorder_recursive(TreeNode *node){
		if(!node) return;
		postorder_recursive(node->left);
		postorder_recursive(node->right);
		ret.push_back(node->val);
	}

	/* sol_2-1: iterative [stack + direction]
	* Time O(n), Space O(n) (store one point)
	*/
	vector<int> postorderTraversal(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode *>sta;
		sta.push(root);
		bool down=true;

		// iteration
		TreeNode *prev = NULL;
		while(!sta.empty()){
			TreeNode *top = sta.top();
			if(down){
				if(top->right) sta.push(top->right);
				if(top->left) sta.push(top->left);
				if(!top->left && !top->right) down=false;
			}else{
				prev = sta.top();
				sta.pop();
				ret.push_back(prev->val);
				if(!sta.empty() && prev!=sta.top()->left && prev!=sta.top()->right) down=true;
			}
		}

		// return
		return ret;
	}

	/* sol_2-2: iterative [stack + curr + prev]
	* Time O(n), Space O(n) (store one point)
	*/
	vector<int> postorderTraversal(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode *>sta;

		// iteration
		TreeNode *prev = NULL, *curr = root;
		while(curr || !sta.empty()){
			if(curr){
				sta.push(curr);
				curr = curr->left;
			}else{
				TreeNode *node = sta.top();
				if(node->right && node->right!=prev){
					curr = node->right;
				}else{
					sta.pop();
					ret.push_back(node->val);
					prev = node;
				}
			}
		}

		// return
		return ret;
	}
};