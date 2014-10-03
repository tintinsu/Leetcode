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
    ListNode *detectCycle(ListNode *head) {
        // find the meeting node
        if(!head) return NULL;
        ListNode *sp1=head, *sp2=head;
        while(sp2->next && sp2->next->next){
            sp1=sp1->next;
            sp2=sp2->next->next;
            if(sp1==sp2) break;
        }
        if(!sp2->next || !sp2->next->next) return NULL;
        
        // find the start node
        sp2 = head;
        while(sp2!=sp1){
            sp2 = sp2->next;
            sp1 = sp1->next;
        }
        
        // return
        return sp2;
    }
};