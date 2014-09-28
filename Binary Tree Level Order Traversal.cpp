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
	/* sol_1: BFS with two additional stacks
	* Time O(n) Space O(n)
	*/
	vector<vector<int> > levelOrder_1(TreeNode *root) {
		// special case
		vector<vector<int> > ret;
		if(!root) return ret;

		vector<TreeNode *>q1, q2;
		q1.push_back(root);
		while(!q1.empty()){
			// check each node
			vector<int>vec;
			for(int i=0;i<q1.size();i++){
				vec.push_back(q1[i]->val);
				if(q1[i]->left) q2.push_back(q1[i]->left);
				if(q1[i]->right) q2.push_back(q1[i]->right);
			}

			// update q1 + clear q2
			q1 = q2;
			q2.clear();
			ret.push_back(vec);
		}

		// return
		return ret;
	}

	/* sol_2: DFS
	* Time O(n) Space O(1)
	*/
	vector<vector<int> > ret;
	vector<vector<int> > levelOrder(TreeNode *root) {
		ret.clear();
		if(!root) return ret;
		dfs(root,0);
		return ret;
	}

	void dfs(TreeNode *node, int level){
		// record the node
		if(ret.size()<level+1){
			vector<int>v;
			ret.push_back(v);
		}
		ret[level].push_back(node->val);

		// check sub trees
		if(node->left) dfs(node->left, level+1);
		if(node->right) dfs(node->right, level+1);
	}
};