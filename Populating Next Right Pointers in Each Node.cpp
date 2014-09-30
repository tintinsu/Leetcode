/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
* Assume: perfect binary tree + no extra space in solution
*/
class Solution {
public:
	/* sol_1: iterative with no extra space
	* Time O(n) Space O(1)
	*/
	void connect(TreeLinkNode *root) {
		TreeLinkNode *head = root;
		while(head){
			// link
			TreeLinkNode *node = head;
			while(node && node->left){
				node->left->next = node->right;
				if(node->next) node->right->next = node->next->left;
				node = node->next;
			}

			// update head
			head = head->left;
		}
	}

	/* sol_2: BFS with extra queues
	* Time O(n) Space O(n)
	*/
	void connect(TreeLinkNode *root) {
		if(!root) return;
		vector<TreeLinkNode*>q1,q2;
		q1.push_back(root);
		while(!q1.empty()){
			for(int i=0;i<q1.size();i++){
				if(i+1<q1.size()) q1[i]->next = q1[i+1];
				if(q1[i]->left) q2.push_back(q1[i]->left);
				if(q1[i]->right) q2.push_back(q1[i]->right);
			}
			q1=q2;
			q2.clear();
		}
	}

	/* sol_3: DFS
	* Time O(n) Space O(1)
	*/
	void connect(TreeLinkNode *root) {
		if(!root || !root->left) return;

		// this node
		root->left->next = root->right;
		if(root->next) root->right->next = root->next->left;

		// children
		connect(root->left);
		connect(root->right);
	}
};