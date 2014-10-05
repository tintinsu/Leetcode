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
    ListNode *insertionSortList(ListNode *head) {
        if(!head) return NULL;
        ListNode **dp = &head;
        dp = &((*dp)->next);
        while(*dp){
            ListNode *key = *dp;
            ListNode **curr = &head;
            while(*curr != key){
                if((*curr)->val > key->val){
                    break;
                }else{
                    curr = &((*curr)->next);
                }
            }
            if(*curr != key){
                *dp = (*dp)->next;
                key->next = *curr;
                *curr = key;
            }else{
                dp = &((*dp)->next);
            }
        }
        return head;
    }
};