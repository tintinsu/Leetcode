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
	/* sol_1: recursive solution
	* Time O(n) Space O(n)
	*/
	vector<int> ret;
	vector<int> preorderTraversal_1(TreeNode *root) {
		ret.clear();
		preorder_recursive(root);
		return ret;
	}
	void preorder_recursive(TreeNode *node){
		if(!node) return;
		ret.push_back(node->val);
		preorder_recursive(node->left);
		preorder_recursive(node->right);
	}

	/* sol_2-1: iterative with a stack
	* Time O(n) Space O(n)
	* Comments: More space + simple logic
	*/
	vector<int> preorderTraversal_2_1(TreeNode *root) {
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode *>sta;
		sta.push(root);

		// iterative
		while(!sta.empty()){
			TreeNode *top = sta.top();
			sta.pop();
			ret.push_back(top->val);

			// push the right
			if(top->right) sta.push(top->right);
			// push the left
			if(top->left) sta.push(top->left);
		}

		// return
		return ret;
	}

	/* sol_2-2: iterative with a stack + direction
	* Time O(n) Space O(n)
	* Comments: less space + more complicated logic
	*/
	vector<int> preorderTraversal_2_2(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode *> sta;
		sta.push(root);
		ret.push_back(root->val);
		bool down = true;

		// iteration
		while(!sta.empty()){
			TreeNode *top = sta.top();
			if(down){
				if(top->left){
					sta.push(top->left); 
					ret.push_back(top->left->val); 
					continue;
				}
				down = false;
			}else{
				sta.pop();
				if(top->right){
					sta.push(top->right);
					ret.push_back(top->right->val);
					down = true;
				}
			}
		}

		// return
		return ret;
	}

	/* sol_2-3: iterative with a stack + curr
	* Time O(n) Space O(n)
	* Comments: less space + more complicated logic
	*/
	vector<int> preorderTraversal(TreeNode *root) {
		// preparation
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode *>sta;
		TreeNode *curr = root;

		// iteration
		while(curr || !sta.empty()){
			if(curr){
				sta.push(curr);
				ret.push_back(curr->val);
				curr = curr->left;
			}else{
				curr = sta.top()->right;
				sta.pop();
			}
		}

		// return
		return ret;
	}

	/* sol_3: iterative
	* Time O(n) Space O(1)
	* Comments: insert curr + remove the end when encountered
	*/
    vector<int> preorderTraversal(TreeNode *root) {
        // preparation
        vector<int> ret;
        if(!root) return ret;
        TreeNode *curr = root;
           
        // iterative
        while(curr){
            ret.push_back(curr->val);
            
            if(curr->left){
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr) prev=prev->right;
                if(prev->right==curr){
                    curr = curr->right;
                    prev->right = NULL;
                    ret.erase(ret.end()-1);
                }else{
                    prev->right = curr;
                    curr = curr->left;
                }
            }else{
                curr = curr->right;
            }
        }
        
        // return
        return ret;
    }
};