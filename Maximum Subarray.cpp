class Solution {
public:
    int maxSubArray(int A[], int n) {
        int *sum_max = new int [n];
        sum_max[0] = A[0];
        int max_val = A[0];
        
        for(int i=1;i<n;i++){
            sum_max[i] = sum_max[i-1]>0?(sum_max[i-1]+A[i]):A[i];
            max_val = max(max_val, sum_max[i]);
        }
        return max_val;
    }
};