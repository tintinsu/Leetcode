class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int>asStart(n, 0), asEnd(n, 0);
        // as start
        int vmin=prices[0];
        for(int i=0;i<n;i++) {
            vmin = min(vmin, prices[i]);
            asStart[i]=prices[i] - vmin;
            if(i>0) asStart[i]=max(asStart[i], asStart[i-1]);
        }
        // as end
        int vmax=prices[n-1];
        for(int i=n-1;i>=0;i--) {
            vmax = max(vmax, prices[i]);
            asEnd[i] = vmax - prices[i];
            if(i<n-1) asEnd[i]=max(asEnd[i], asEnd[i+1]);
        }
        // double heap
        int max_val=0;
        for(int i=0;i<n;i++){
            int sum = asEnd[i];
            if(i>0) sum+=asStart[i-1];
            max_val = max(max_val, sum);
        }
        // return
        return max_val;
    }
};