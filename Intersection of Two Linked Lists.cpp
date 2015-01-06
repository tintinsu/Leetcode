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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        // connect the tail to the head
        ListNode *tail = headB;
        while(tail->next) tail = tail->next;
        tail->next = headA;
        
        // cycle analysis
        ListNode *sp1=headB, *sp2=headB;
        while(sp2->next && sp2->next->next){
            sp2=sp2->next->next;
            sp1=sp1->next;
            
            if(sp1==sp2){
                sp2 = headB;
                while(sp1 != sp2){
                    sp1 = sp1->next;
                    sp2 = sp2->next;
                }
                tail->next = NULL;
                return sp1;
            }
        }
        
        tail->next = NULL;
        return NULL;
    }
};
