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
    vector<int> inorder, postorder;
    TreeNode *buildTree(vector<int> &inorder1, vector<int> &postorder1) {
        inorder = inorder1;
        postorder = postorder1;
        if(inorder.size() == 0) return NULL;
        return buildTree(0,inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode *buildTree(int in0,int in1,int post0,int post1){
        if(in0>in1) return NULL;
        
        // create a node
        TreeNode *node = new TreeNode(postorder[post1]);
        
        // range computation
        vector<int>::iterator it = find(inorder.begin()+in0, inorder.begin()+in1+1, node->val);
        int idx = it - inorder.begin();
        int nLeft = idx - in0;
        
        // assign left & right
        node->left = buildTree(in0, idx-1, post0, post0+nLeft-1);
        node->right = buildTree(idx+1,in1, post0+nLeft,post1-1);
        
        // return
        return node;
    }
};