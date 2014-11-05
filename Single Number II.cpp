class Solution {
public:
    int singleNumber(int A[], int n) {
        int val = 0;
        for(int i=0;i<32;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += (A[j]>>i)&1;
            }
            val += (sum%3)<<i;
        }
        return val;
    }
};