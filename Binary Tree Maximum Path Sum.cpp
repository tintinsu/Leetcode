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
    int ret;
    int maxPathSum(TreeNode *root) {
        ret = INT_MIN;
        if(!root) return 0;
        int max_branch_sum = 0;
        maxPathSum(root, max_branch_sum);
        return ret;
    }
    
    void maxPathSum(TreeNode *node, int &max_branch_sum){        
        // recursive
        int max_left=0, max_right=0;
        if(node->left) maxPathSum(node->left, max_left);
        if(node->right) maxPathSum(node->right, max_right);
        
        // post-order traversal
        int max_sum = max(max(node->val, node->val+max_left), max(node->val+max_right, node->val+max_left+max_right));
        ret = max(ret, max_sum);
        max_branch_sum = max(node->val, max(node->val+max_left, node->val+max_right));
    }
};