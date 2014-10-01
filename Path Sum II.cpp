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
    vector<vector<int> > ret;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ret.clear();
        if(!root) return ret;
        vector<int> vec;
        pathSum(root, vec, 0, sum);
        return ret;
    }
    
    void pathSum(TreeNode *node, vector<int> vec, int local_sum, int sum){
        local_sum += node->val;
        vec.push_back(node->val);
        
        // leaf node
        if(!node->left && !node->right){
            if(local_sum==sum) ret.push_back(vec);
            return;
        }
        
        // otherwise
        if(node->left) pathSum(node->left, vec, local_sum, sum);
        if(node->right) pathSum(node->right, vec, local_sum, sum);
    }
};