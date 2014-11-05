/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        map<RandomListNode *, RandomListNode *>ma;
        RandomListNode *node=head;
        while(node){
            if(ma.find(node)==ma.end()){
                RandomListNode *copy = new RandomListNode(node->label);
                ma[node]=copy;
            }
            if(node->next){
                if(ma.find(node->next)==ma.end()){
                    RandomListNode *copy = new RandomListNode(node->next->label);
                    ma[node->next]=copy;
                }
                ma[node]->next = ma[node->next];
            }
            if(node->random){
                if(ma.find(node->random)==ma.end()){
                    RandomListNode *copy = new RandomListNode(node->random->label);
                    ma[node->random]=copy;
                }
                ma[node]->random = ma[node->random];
            }
            node = node->next;
        }
        return ma[head];
    }
};