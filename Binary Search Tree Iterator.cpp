/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *curr;
    stack<TreeNode *>sta;
    
public:
    BSTIterator(TreeNode *root) {
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr || !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
        while(curr){
            sta.push(curr);
            curr = curr->left;
        }
        TreeNode *node = sta.top();
        sta.pop();
        curr = node->right;
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
