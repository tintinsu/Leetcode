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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *sp1=head, *sp2=head;
        while(sp2->next && sp2->next->next){
            sp1 = sp1->next;
            sp2 = sp2->next->next;
            if(sp1==sp2) return true;
        }
        return false;
    }
};