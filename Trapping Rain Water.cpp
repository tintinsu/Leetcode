class Solution {
public:
    int trap(int A[], int n) {
        // check size
        if(n==0) return 0;
        
        // max from left
        vector<int>left(n,0);
        left[0]=A[0];
        for(int i=1;i<n;i++) left[i]=max(left[i-1], A[i]);
        
        // max from right
        vector<int>right(n,0);
        right[n-1]=A[n-1];
        for(int j=n-2;j>=0;j--) right[j]=max(right[j+1], A[j]);
        
        // real size
        int area = 0;
        for(int i=0;i<n;i++) area += (min(left[i], right[i]) - A[i]);
        
        // return
        return area;
    }
};