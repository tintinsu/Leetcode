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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *n1, TreeNode *n2){
        if(!n1 && !n2) return true;
        if(n1 && n2 && n1->val==n2->val && isSymmetric(n1->left, n2->right) && isSymmetric(n1->right, n2->left)) return true;
        return false;
    }

	/* sol_2: bfs iterative method */
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        queue<TreeNode *>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *n1 = q.front(); q.pop();
            TreeNode *n2 = q.front(); q.pop();
            if(!n1 && !n2) continue;
            if(n1 && n2 && n1->val==n2->val){
                q.push(n1->left);
                q.push(n2->right);
                q.push(n1->right);
                q.push(n2->left);
                continue;
            }
            return false;
        }
        return true;
    }
};