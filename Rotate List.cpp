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
    ListNode *rotateRight(ListNode *head, int k) {
        // find the exact k value
        int n=0;
        ListNode *curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }
        if(n==0) return NULL;
        k = k%n;
        if(k==0) return head;
        
        // find the k to the last
        ListNode *tail=head;
        ListNode **dp = &head;
        for(int i=0;i<k-1;i++) tail=tail->next;
        while(tail->next){
            tail = tail->next;
            dp = &((*dp)->next);
        }
        
        // move the end to the front
        tail->next = head;
        ListNode* newHead = *dp;
        *dp=NULL;
        
        // return
        return newHead;
    }
};