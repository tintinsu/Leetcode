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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(p && q && p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }

	/* sol_2: bfs with iteration */
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *>qu;
        qu.push(p);
        qu.push(q);
        while(!qu.empty()){
            TreeNode *n1=qu.front(); qu.pop();
            TreeNode *n2=qu.front(); qu.pop();
            if(!n1 && !n2) continue;
            if(n1 && n2 && n1->val==n2->val){
                qu.push(n1->left);
                qu.push(n2->left);
                qu.push(n1->right);
                qu.push(n2->right);
                continue;
            }
            return false;
        }
        return true;
    }
};