class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // general
        for(int i=0;i<n;){
            int val = A[i];
            if(val>=1 && val<=n && A[val-1]!=val){
                int tmp = A[val-1];
                A[val-1] = A[i];
                A[i] = tmp;
            }else i++;
        }
        
        // return
        for(int i=0;i<n;i++){
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};