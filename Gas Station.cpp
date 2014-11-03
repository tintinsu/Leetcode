class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
        if(n==0) return -1;
        int idx_start = 0;
        map<int, bool>ma;
        while(1){
            int rest = 0, idx = idx_start;
            while(rest + gas[idx%n] - cost[idx%n]>=0){
                rest += (gas[idx%n] - cost[idx%n]);
                idx++;
                if(idx%n == idx_start%n) return idx_start%n;
            }
            if(ma.find(idx%n)!=ma.end()) return -1;
            ma[idx%n]=true;
            idx_start = (idx+1)%n;
        }
    }
};