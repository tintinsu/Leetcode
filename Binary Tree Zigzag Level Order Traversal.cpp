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
	/* sol_1: BFS with extra queues
	* Time O(n) Space O(n)
	*/
	vector<vector<int> > zigzagLevelOrder_bfs(TreeNode *root) {
		vector<vector<int> >ret;
		if(!root) return ret;
		vector<TreeNode *>q1, q2;
		q1.push_back(root);
		bool order=true;

		while(!q1.empty()){
			vector<int> v;
			for(int i=0;i<q1.size();i++){
				if(order){
					v.push_back(q1[i]->val);
				}else{
					v.insert(v.begin(), q1[i]->val);
				}
				if(q1[i]->left) q2.push_back(q1[i]->left);
				if(q1[i]->right) q2.push_back(q1[i]->right);
			}

			// organize
			ret.push_back(v);
			order = !order;
			q1 = q2;
			q2.clear();
		}

		return ret;
	}

	/* sol_2: DFS
	* Time O(n) Space O(1)
	*/
	vector<vector<int> >ret;
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		ret.clear();
		dfs(root, 0);
		return ret;
	}

	void dfs(TreeNode *node, int level){
		if(!node) return;

		// this node
		if(level+1>ret.size()){
			vector<int>v;
			ret.push_back(v);
		}
		if(level%2==0){
			ret[level].push_back(node->val);
		}else{
			ret[level].insert(ret[level].begin(), node->val);
		}

		// children
		dfs(node->left, level+1);
		dfs(node->right, level+1);
	}
};