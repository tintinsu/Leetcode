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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode **dp = &head;
        while(checkk(*dp, k)){
            ListNode *rev=NULL, *tail=NULL;
            for(int i=0;i<k;i++){
                // remove
                ListNode *node = *dp;
                *dp = (*dp)->next;
                
                // insert
                if(!tail) tail=node;
                node->next = rev;
                rev = node;
            }
            
            // insert
            tail->next = *dp;
            *dp = rev;
            for(int i=0;i<k;i++) dp=&((*dp)->next);
        }
        return head;
    }
    bool checkk(ListNode*node, int k){
        for(int i=0;i<k;i++){
            if(!node) return false;
            node=node->next;
        }
        return true;
    }
};