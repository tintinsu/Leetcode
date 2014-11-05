class Solution {
public:
    int singleNumber(int A[], int n) {
        int val = 0;
        for(int i=0;i<n;i++) val = val^A[i];
        return val;
    }
};