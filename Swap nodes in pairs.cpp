/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode**dp = &head;
        
        // swap
        while(*dp && (*dp)->next){
            ListNode *node = *dp;
            *dp = (*dp)->next;
            node->next = (*dp)->next;
            (*dp)->next = node;
            
            // update
            dp = &((*dp)->next);
            dp = &((*dp)->next);
        }
        
        // return
        return head;
    }
};