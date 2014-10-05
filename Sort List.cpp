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
    ListNode *sortList(ListNode *head) {
        // special
        if(!head || !head->next) return head;
        
        // separate
        ListNode *sp1=head, *sp2=head;
        while(sp2->next && sp2->next->next){
            sp1=sp1->next;
            sp2=sp2->next->next;
        }
        
        // recursive
        ListNode *head2 = sp1->next;
        sp1->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(head2);
        
        // merge
        ListNode **dp1=&l1;
        while(*dp1 && l2){
            if(l2->val <= (*dp1)->val){
                ListNode *node = l2;
                l2 = l2->next;
                node->next = *dp1;
                *dp1 = node;
            }
            dp1 = &((*dp1)->next);
        }
        if(l2) *dp1=l2;
        
        // return
        return l1;
    }
};