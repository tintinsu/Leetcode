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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        return hasPathSum(root, 0, sum);
    }
    
    bool hasPathSum(TreeNode *node, int local_sum, int sum){
        local_sum += node->val;
        if(!node->left && !node->right && local_sum==sum) return true;
        
        if(node->left && hasPathSum(node->left,local_sum,sum)) return true;
        if(node->right && hasPathSum(node->right,local_sum,sum)) return true;
        return false;
    }
};