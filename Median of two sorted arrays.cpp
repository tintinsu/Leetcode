class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2 == 1){
            return 1.0*findMedianSortedArrays(A,0,m-1,B,0,n-1,(m+n)/2);
        }else{
            return (findMedianSortedArrays(A,0,m-1,B,0,n-1,(m+n)/2) + findMedianSortedArrays(A,0,m-1,B,0,n-1,(m+n)/2-1))/2.0;
        }
    }
    
    int findMedianSortedArrays(int A[], int a0, int a1, int B[], int b0, int b1, int idx){
        // special
        if(a0>a1) return B[b0+idx];
        if(b0>b1) return A[a0+idx];
        
        // general find the middle
        int am = (a0+a1)/2;
        int n0=b0, n1=b1, nm;
        while(n0+1<n1){
            nm = (n0+n1)/2;
            if(B[nm] == A[am]) break;
            if(B[nm] < A[am]){
                n0=nm;
            }else{
                n1=nm;
            }
        }
        if(A[am]>=B[n1])
            nm=n1;
        else if(A[am]>=B[n0])
            nm=n0;
        else
            nm=n0-1;
        
        // return
        int nLeft = am-a0+1 + nm-b0+1;
        if(idx+1 == nLeft)
            return A[am];
        else if(idx+1 < nLeft)
            return findMedianSortedArrays(A,a0,am-1,B,b0,nm,idx);
        else
            return findMedianSortedArrays(A,am+1,a1,B,nm+1,b1,idx-nLeft);
    }
};