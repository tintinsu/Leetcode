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
	/* sol_1: dfs */
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        int min_left = minDepth(root->left);
        int min_right = minDepth(root->right);
        if(min_left==0 || min_right==0) return 1+max(min_left, min_right);
        return 1+min(min_left, min_right);
    }

	/* sol_1-another: dfs*/
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(root->left && root->right) return 1+min(minDepth(root->left), minDepth(root->right));
        TreeNode *node = root->left?root->left:(root->right?root->right:NULL);
        return node?minDepth(node)+1 : 1;
    }
    
	/* sol_2: bfs 
	*  Method: find the first leaf node with bfs
	*/
    int minDepth(TreeNode *root) {
        // preparation
        if(!root) return 0;
        int level = 1;
        vector<TreeNode *> q1, q2;
        q1.push_back(root);
        
        // bfs
        while(!q1.empty()){
            for(int i=0;i<q1.size();i++){
                if(!q1[i]->left && !q1[i]->right) return level;
                if(q1[i]->left) q2.push_back(q1[i]->left);
                if(q1[i]->right) q2.push_back(q1[i]->right);
            }
            
            // update
            q1 = q2;
            q2.clear();
            level++;
        }
    }
};
