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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry_in=0;
        ListNode *ret=NULL;
        ListNode **dp = &ret;
        
        // sum
        while(l1 || l2 || carry_in>0){
            int sum = carry_in;
            if(l1) {sum+=l1->val;l1=l1->next;}
            if(l2) {sum+=l2->val;l2=l2->next;}
            *dp = new ListNode(sum%10);
            
            // update
            dp = &((*dp)->next);
            carry_in = sum/10;
        }
        
        // return
        return ret;
    }
};