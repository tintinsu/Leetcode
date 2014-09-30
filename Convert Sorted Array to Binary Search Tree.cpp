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
    vector<int> num;
    TreeNode *sortedArrayToBST(vector<int> &num1) {
        num = num1;
        return sortedArrayToBST(0, num.size()-1);
    }
    
    TreeNode *sortedArrayToBST(int start, int end){
        if(start > end) return NULL;
        int m=(start+end)/2;
        TreeNode *node=new TreeNode(num[m]);
        node->left = sortedArrayToBST(start, m-1);
        node->right = sortedArrayToBST(m+1,end);
        return node;
    }
};