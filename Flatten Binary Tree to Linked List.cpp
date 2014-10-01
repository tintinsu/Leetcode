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
    void flatten(TreeNode *root) {
        if(!root) return;
        flatten(root->right);
        if(root->left){
            flatten(root->left);
            TreeNode *tail=root->left;
            while(tail->right) tail=tail->right;
            tail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
    }
};