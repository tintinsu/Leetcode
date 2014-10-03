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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **dp = &head;
        while(*dp && (*dp)->next){
            if((*dp)->val == ((*dp)->next)->val){
                *dp = (*dp)->next;
            }else{
                dp = &((*dp)->next);
            }
        }
        return head;
    }
};