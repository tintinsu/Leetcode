class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia=m-1, ib=n-1, idx=m+n-1;
		// if both existing
        while(ia>=0 && ib>=0){
            A[idx--]=(B[ib]>=A[ia])?B[ib--]:A[ia--];
        }
		// if only B left
        while(ib>=0) A[idx--]=B[ib--];
    }
};