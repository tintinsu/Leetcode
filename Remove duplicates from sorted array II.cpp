class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1) return n;
        int i=-1, j=0, k=1;
        while(k<n){
            if(A[j]==A[k]) {k++;continue;}
            if(A[j]!=A[k]&&j+1==k) {A[++i]=A[j];j++;k++;continue;}
            A[++i]=A[j];
            A[++i]=A[j];
            j=k;k++;
        }
        // last
        if(A[n-2]==A[n-1]) A[++i]=A[n-1];
        A[++i]=A[n-1];
        
        // return
        return i+1;
    }
};