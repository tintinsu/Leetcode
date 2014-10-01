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
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalanced(root, height);
    }
    
    bool isBalanced(TreeNode *node, int &height){
        if(!node) return true;
        int h1=0, h2=0;
        if(!isBalanced(node->left, h1)) return false;
        if(!isBalanced(node->right, h2)) return false;
        if(abs(h1-h2)>1) return false;
        height=max(h1,h2)+1;
        return true;
    }
};