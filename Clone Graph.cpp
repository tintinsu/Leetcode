/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	/* sol_1: BFS */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>ma;
        queue<UndirectedGraphNode *>qu;
        
        ma[node] = new UndirectedGraphNode (node->label);
        qu.push(node);
        while(!qu.empty()){
            UndirectedGraphNode *top = qu.front();
            qu.pop();
            vector<UndirectedGraphNode *>nei = top->neighbors;
            for(int i=0;i<nei.size();i++){
                UndirectedGraphNode *child= nei[i];
                if(ma.find(child)==ma.end()) {
                    ma[child] = new UndirectedGraphNode (child->label);
                    qu.push(child);
                }
                ma[top]->neighbors.push_back(ma[child]);
            }
        }
        return ma[node];
    }

	/* sol_2: DFS */
    map<UndirectedGraphNode *, UndirectedGraphNode *>ma;
    UndirectedGraphNode *cloneGraph_2(UndirectedGraphNode *node) {
        if(!node) return NULL;
        ma.clear();
        return dfs(node);
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node){
        if(ma.find(node)!=ma.end()) return ma[node];
        ma[node] = new UndirectedGraphNode(node->label);
        
        vector<UndirectedGraphNode *>nei = node->neighbors;
        for(int i=0;i<nei.size();i++){
            ma[node]->neighbors.push_back(dfs(nei[i]));
        }
        return ma[node];
    }
};