class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n==0) return 0;
        int vmin=prices[0], largest=0;
        for(int i=1;i<n;i++){
            vmin=min(vmin, prices[i]);
            int diff = prices[i] - vmin;
            if(diff > largest) largest = diff;
        }
        return largest;
    }
};