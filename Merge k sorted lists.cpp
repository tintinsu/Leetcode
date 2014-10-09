#include<iostream>
#include<vector>
#include<queue>
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

	// sol_2: priority queue
    ListNode *mergeKLists_2(vector<ListNode *> &lists) {
        // construct a priority queue
        priority_queue<ListNode *, vector<ListNode *>, MyCompare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push(lists[i]);
        }
        // merge
        ListNode *head=NULL, **dp=&head;
        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();
            // sorting
            *dp = node;
            dp = &((*dp)->next);
            // push the next element
            if(node->next) pq.push(node->next);
        }
        // return
        return head;
    }
};

class MyCompare{
public:
    bool operator()(ListNode *n1, ListNode *n2){
        return n1->val > n2->val;
    }
};

int main()
{
	priority_queue<int>pq;
	int arr[4]={4,1,5,6};
	for(int i=0;i<4;i++) pq.push(arr[i]);
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	system("pause");
	return 1;
}