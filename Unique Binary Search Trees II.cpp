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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end){
        vector<TreeNode *>vec;
        if(start > end){
            vec.push_back(NULL);
            return vec;
        }
        
        for(int mid=start; mid<=end; mid++){
            vector<TreeNode *>left = generateTrees(start, mid-1);
            vector<TreeNode *>right = generateTrees(mid+1, end);
            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    TreeNode *node = new TreeNode(mid);
                    node->left = left[i];
                    node->right = right[j];
                    vec.push_back(node);
                }
            }
        }
        
        return vec;
    }
};