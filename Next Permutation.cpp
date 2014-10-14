class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n=num.size();
        if(n==0) return;
        
        // find the (min, max) neighbor
        bool sign=false;
        int i;
        for(i=n-1;i>0;i--){
            if(num[i] > num[i-1]){
                sign = true;
                break;
            }
        }
        
        // find the min-max value
        if(sign){
            int min_max = num[i], idx_min_max = i, j;
            for(j=i;j<n;j++){
                if(num[j]>num[i-1] && num[j]<min_max){
                    idx_min_max = j;
                    min_max = num[j];
                }
            }
            int tmp=num[idx_min_max]; num[idx_min_max]=num[i-1]; num[i-1]=tmp;
        }
        
        // sort
        sort(num.begin()+i, num.begin()+n); 
    }
};