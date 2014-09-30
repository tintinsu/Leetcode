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

	/* sol_1: post-order traversal
	* Time O(n) Space O(1)
	*/
    bool isValidBST_1(TreeNode *root) {
        int minv, maxv;
        return isValidBST(root,minv,maxv);
    }
    bool isValidBST(TreeNode *root, int &min_val, int &max_val){
        if(!root) return true;
        min_val=root->val; 
        max_val=root->val;
        
        // update by left
        if(root->left){
            int min1, max1;
            if(!isValidBST(root->left,min1,max1)) return false;
            if(max1>=root->val) return false;
            min_val=min1;
        }
        
        // update by right
        if(root->right){
            int min2, max2;
            if(!isValidBST(root->right,min2,max2)) return false;
            if(min2<=root->val) return false;
            max_val=max2;
        }
        
        // check this node
        return true;
    }

	/* sol_2: in-order traversal
	* Reason: a flattened BST with in-order traversal is a sorted array
	* Time O(n) Space O(1)
	*/
    TreeNode *last;
    bool isValidBST_2(TreeNode *root) {
        last = NULL;
        return isValidBST_inorder(root);
    }
    bool isValidBST_inorder(TreeNode *node){
        if(!node) return true;
        
        // left
        if(!isValidBST_inorder(node->left)) return false;
        
        // node
        if(last && last->val >= node->val) return false;
        last = node;
        
        // right
        if(!isValidBST_inorder(node->right)) return false;
        
        return true;
    }
};