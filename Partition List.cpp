#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *ge=NULL, **dp_ge=&ge;
		ListNode **dp = &head;

		// separate
		while(*dp){
			if((*dp)->val >= x){
				*dp_ge = *dp;
				*dp = (*dp)->next;
				dp_ge = &((*dp_ge)->next);
			}else{
				dp = &((*dp)->next);
			}
		}

		// append
		*dp = ge;
		*dp_ge = NULL;

		// return
		return head;
	}
};

int main()
{
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(1);
	n1->next = n2;
	Solution sol;
	ListNode *head = sol.partition(n1, 2);
	while(head){
		cout << head->val << " ";
		head = head->next;
	}

	system("pause");
	return 1;
}