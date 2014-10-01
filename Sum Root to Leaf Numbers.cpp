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
	/* sol_1: DFS
	* Time O(n) Space O(1) + recursive overhead
	*/
    int sum;
    int sumNumbers(TreeNode *root) {
        sum = 0;
        if(!root) return sum;
        sumNumbers(root, 0);
        return sum;
    }
    void sumNumbers(TreeNode *node, int local_sum){
        // update this node
        local_sum = 10*local_sum + node->val;
        
        // check leaf
        if(!node->left && !node->right){
            sum += local_sum;
            return;
        }
        
        // recursive
        if(node->left) sumNumbers(node->left, local_sum);
        if(node->right) sumNumbers(node->right, local_sum);
    }

	/* sol_2: BFS with pair
	* Time O(n) Space O(n)
	*/
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if(!root) return sum;
        vector<pair<TreeNode*, int>> q1, q2;
        q1.push_back(make_pair(root, 0));
        while(!q1.empty()){
            // loop over q1
            for(int i=0;i<q1.size();i++){
                // this node
                TreeNode *node = q1[i].first;
                int local_sum = q1[i].second*10 + node->val;
                if(!node->left && !node->right) sum+=local_sum;
                if(node->left) q2.push_back(make_pair(node->left, local_sum));
                if(node->right) q2.push_back(make_pair(node->right, local_sum));
            }
            // update q1, q2
            q1=q2;
            q2.clear();
        }
        return sum;
    }
};