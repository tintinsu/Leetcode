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
    TreeNode *last, *min_node, *max_node;
    void recoverTree(TreeNode *root) {
        last = NULL;
        min_node = NULL;
        max_node = NULL;
        recoverTree1(root);
        if(min_node && max_node){
            int tmp = min_node->val;
            min_node->val = max_node->val;
            max_node->val = tmp;
        }
    }
    
    void recoverTree1(TreeNode *node){
        if(!node) return;
        recoverTree1(node->left);
        if(last && last->val > node->val){
            if(!min_node && !max_node){
                min_node = node;
                max_node = last;
            }else{
                min_node = (node->val < min_node->val)?node:min_node;
                max_node = (last->val > max_node->val)?last:max_node;
            }
        }
        last = node;
        recoverTree1(node->right);
    }
};