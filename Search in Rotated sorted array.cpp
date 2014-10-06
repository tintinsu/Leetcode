class Solution {
public:
    int search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }
    
    int search(int A[], int n0, int n1, int target) {
        // special case
        if(n0>n1) return -1;
        
        // mid node
        int m = (n0+n1)/2;
        if(A[m]==target) return m;
        
        // choose side
        if(n0<=m-1 && A[n0]<=A[m-1]){
            // left in order
            if(A[n0]<=target && target<=A[m-1]){
                return search(A,n0,m-1,target);
            }else{
                return search(A,m+1,n1,target);
            }
        }else if(m+1<=n1 && A[m+1]<=A[n1]){
            // right in order
            if(A[m+1]<=target && target<=A[n1]){
                return search(A,m+1,n1,target);
            }else{
                return search(A,n0,m-1,target);
            }
        }
        return -1;
    }
};