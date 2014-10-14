class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int j=0;
        for(int i=1;i<n;i++){
            if(A[i]!=A[j]) A[++j]=A[i];
        }
        return j+1;
    }
};