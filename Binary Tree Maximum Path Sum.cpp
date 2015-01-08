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
    
    /* another way of the recursive function */
    void recursive(TreeNode *node, int &max_path_sum){
        // post order + update two sums
        max_path_sum = node->val;
        int local_sum = node->val;
        
        if(node->left){
            int max_left;
            recursive(node->left, max_left);
            max_path_sum = max(max_path_sum, node->val + max_left);
            local_sum = max(local_sum, local_sum + max_left);
        }
        
        if(node->right){
            int max_right;
            recursive(node->right, max_right);
            max_path_sum = max(max_path_sum, node->val + max_right);
            local_sum = max(local_sum, local_sum + max_right);
        }
        
        maxsum = max(maxsum, local_sum);
    }
};
