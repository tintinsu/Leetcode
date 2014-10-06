class Solution {
public:
    bool search(int A[], int n, int target) {
        return search(A,0,n-1,target);
    }
    
    bool search(int A[],int n0,int n1,int target){
        if(n0>n1) return false;
        
        int m=(n0+n1)/2;
        if(A[m]==target) return true;
        
        if(A[n0]==A[n1]){
            return A[n0]==target?true:search(A,n0+1,n1-1,target);
        }else if(n0<=m-1 && A[n0]<=A[m-1]){
            if(A[n0]<=target && target<=A[m-1]){
                return search(A,n0,m-1,target);
            }else{
                return search(A,m+1,n1,target);
            }
        }else if(m+1<=n1 && A[m+1]<=A[n1]){
            if(A[m+1]<=target && target<=A[n1]){
                return search(A,m+1,n1,target);
            }else{
                return search(A,n0,m-1,target);
            }
        }
        return false;
    }
};