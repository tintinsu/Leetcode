/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        
        // runner method
        ListNode **dp=&head, *tail=head;
        while(tail->next && tail->next->next){
            dp=&((*dp)->next);
            tail=tail->next->next;
        }
        
        // assign nodes
        TreeNode *node = new TreeNode((*dp)->val);
        node->right=sortedListToBST((*dp)->next);
        *dp=NULL;
        node->left=sortedListToBST(head);
        return node;
    }
};