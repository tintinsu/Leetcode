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
        bool isRepetitive = false;
        ListNode **dp = &head;
        while(*dp && (*dp)->next){
            if((*dp)->val == ((*dp)->next)->val){
                isRepetitive = true;
                *dp = (*dp)->next;
            }else if(isRepetitive){
                *dp = (*dp)->next;
                isRepetitive = false;
            }else{
                dp = &((*dp)->next);
            }
        }
        if(isRepetitive) *dp = (*dp)->next;
        return head;
    }
};