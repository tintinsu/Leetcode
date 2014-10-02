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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode **dp_l1=&l1, **dp_l2=&l2;
        // merge into l1
        while(*dp_l1 && *dp_l2){
            if((*dp_l2)->val < (*dp_l1)->val){
                ListNode *node = *dp_l2;
                *dp_l2 = (*dp_l2)->next;
                node->next = *dp_l1;
                *dp_l1 = node;
            }
            dp_l1 = &((*dp_l1)->next);
        }
        
        // if l2 left
        if(*dp_l2) *dp_l1=*dp_l2;
        
        // return l1
        return l1;
    }
};