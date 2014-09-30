/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	/* sol_1: BFS [iterative with extra space]
	* Time O(n) Space O(n)
	*/
	void connect(TreeLinkNode *root) {
		if(!root) return;
		vector<TreeLinkNode *>q1,q2;
		q1.push_back(root);

		while(!q1.empty()){
			// this layer
			for(int i=0;i<q1.size();i++){
				if(i+1<q1.size()) q1[i]->next=q1[i+1];
				if(q1[i]->left) q2.push_back(q1[i]->left);
				if(q1[i]->right) q2.push_back(q1[i]->right);
			}
			// update
			q1=q2;
			q2.clear();
		}
	}

	/* sol_2: iterative [no extra space]
	* Time O(n) Space O(1)
	*/
	void connect(TreeLinkNode *root) {
		TreeLinkNode *head = root;
		TreeLinkNode *row1, *row2;
		while(head){
			row1 = head;
			head = NULL;
			while(row1){
				if(row1->left){
					if(!head){
						head = row1->left;
						row2 = head;
					}else{
						row2->next = row1->left;
						row2 = row2->next;
					}
				}
				if(row1->right){
					if(!head){
						head = row1->right;
						row2 = head;
					}else{
						row2->next = row1->right;
						row2 = row2->next;
					}
				}
				row1=row1->next;
			}
		}
	}

	/* sol_3: recursive without extra space
	* Time O(n) Space O(1)
	*/
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *row1 = root, *head = NULL, *row2;
        while(row1){
            if(row1->left){
                if(!head){
                    head = row1->left;
                    row2 = head;
                }else{
                    row2->next = row1->left;
                    row2 = row2->next;
                }
            }
            if(row1->right){
                if(!head){
                    head = row1->right;
                    row2 = head;
                }else{
                    row2->next = row1->right;
                    row2 = row2->next;
                }
            }
            row1=row1->next;
        }
        connect(head);
    }
};