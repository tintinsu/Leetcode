class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRange(A,0,n-1,target);
    }
    
    vector<int> searchRange(int A[],int n0,int n1,int target){
        // special
        if(n0>n1){
            int arr[2]={-1,-1};
            vector<int>v(arr,arr+2);
            return v;
        }
        
        // mid
        int m=(n0+n1)/2;
        // choose side
        if(A[m]==target){
            int i0=m, i1=m;
            while(i0-1>=n0 && target==A[i0-1]) i0--;
            while(i1+1<=n1 && target==A[i1+1]) i1++;
            int arr[2]={i0,i1};
            vector<int>v(arr,arr+2);
            return v;
        }else if(A[m]<target){
            return searchRange(A,m+1,n1,target);
        }else{
            return searchRange(A,n0,m-1,target);
        }
    }
};