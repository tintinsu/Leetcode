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
    void reorderList(ListNode *head) {
        if(!head) return;
        // runner technique
        ListNode *sp1=head, *sp2=head;
        while(sp2->next && sp2->next->next){
            sp1 = sp1->next;
            sp2 = sp2->next->next;
        }
        ListNode *head2 = sp1->next;
        sp1->next = NULL;
        
        // reverse second half
        ListNode *rev = NULL;
        while(head2){
            ListNode *node = head2;
            head2 = head2->next;
            node->next = rev;
            rev = node;
        }
        
        // insert into first half
        ListNode *curr = head;
        while(rev){
            ListNode *node = rev;
            rev = rev->next;
            node->next = curr->next;
            curr->next = node;
            curr = curr->next->next;
        }
    }
};