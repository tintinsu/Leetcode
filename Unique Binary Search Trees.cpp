class Solution {
public:
	/* sol_1: 1d DP
	*/
    int numTrees(int n) {
        vector<int> cnt(n+1, 0);
        cnt[0] = 1;
        for(int nNodes=1; nNodes<=n; nNodes++){
            for(int i=1;i<=nNodes;i++){
                int nLeft = i-1;
                int nRight = nNodes-i;
                cnt[nNodes] += cnt[nLeft]*cnt[nRight];
            }
        }
        return cnt[n];
    }
};