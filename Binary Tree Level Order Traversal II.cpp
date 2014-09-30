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
	/* sol_1: BFS + extra queues
	* Time O(n) Space O(n)
	*/
	vector<vector<int> > levelOrderBottom_extra(TreeNode *root) {
		// preparation
		vector<vector<int> > ret;
		if(!root) return ret;
		vector<TreeNode *> q1,q2;
		q1.push_back(root);

		// loop
		while(!q1.empty()){
			vector<int>v;
			for(int i=0;i<q1.size();i++){
				v.push_back(q1[i]->val);
				if(q1[i]->left) q2.push_back(q1[i]->left);
				if(q1[i]->right) q2.push_back(q1[i]->right);
			}

			ret.insert(ret.begin(), v);
			q1 = q2;
			q2.clear();
		}

		// return 
		return ret;
	}

	/* sol_2: DFS
	* Time O(n) Space O(1)
	*/
	vector<vector<int> > ret;
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		ret.clear();
		dfs(root,0);
		return ret;
	}

	void dfs(TreeNode *node, int level){
		if(!node) return;

		// this node
		if(level+1 > ret.size()){
			vector<int> v;
			ret.insert(ret.begin(), v);
		}
		ret[ret.size()-1-level].push_back(node->val);

		// two children
		dfs(node->left, level+1);
		dfs(node->right, level+1);
	}
};