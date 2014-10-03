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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode **dp = &head;
        
        // jump to m
        for(int i=0;i<m-1;i++) dp=&((*dp)->next);
        
        // remove (n-m+1) nodes and insert head of another
        ListNode *tail=NULL, *rev=NULL;
        for(int i=0;i<n-m+1;i++){
            ListNode *node = *dp;
            *dp = (*dp)->next;
            if(!tail) tail=node;
            node->next = rev;
            rev = node;
        }
        
        // insert the reversed nodes
        tail->next = *dp;
        *dp = rev;
        
        // return
        return head;
    }
};