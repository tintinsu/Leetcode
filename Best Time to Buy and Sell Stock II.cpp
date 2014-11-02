class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n==0) return 0;
        int minv=prices[0], sum=0;
        for(int i=1;i<n;i++){
            if(prices[i]<=minv){
                minv = prices[i];
            }else{
                if(i==n-1){
                    sum+=(prices[i]-minv);
                }else if(prices[i]>=prices[i+1]){
                    sum+=(prices[i]-minv);
                    minv=prices[i+1];
                }
            }
        }
        return sum;
    }
};