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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // find the tail
        ListNode *tail = head;
        // assume n is always avalid
        for(int i=0;i<n-1;i++) tail=tail->next;
        
        // move to the tail
        ListNode **dp = &head;
        while(tail->next){
            tail = tail->next;
            dp = &((*dp)->next);
        }
        
        // remove
        *dp = (*dp)->next;
        
        // return
        return head;
    }
};