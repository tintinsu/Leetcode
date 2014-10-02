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
	/* sol_1: divide-and-conquer
	Time O(Nlgk), suppose N=nk, k=#lists
	*/
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // special case
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        // recursive case
        int mid = lists.size()/2;
        vector<ListNode *> v1(lists.begin(), lists.begin()+mid);
        ListNode *l1 = mergeKLists(v1);
        vector<ListNode *> v2(lists.begin()+mid, lists.end());
        ListNode *l2 = mergeKLists(v2);
        
        // merge two 
        ListNode **dp_l1=&l1, **dp_l2=&l2;
        while(*dp_l1 && *dp_l2){
            if((*dp_l2)->val < (*dp_l1)->val){
                ListNode *node = *dp_l2;
                *dp_l2 = (*dp_l2)->next;
                node->next = *dp_l1;
                *dp_l1 = node;
            }
            dp_l1 = &((*dp_l1)->next);
        }
        if(*dp_l2) *dp_l1=*dp_l2;
        
        // return
        return l1;
    }
};