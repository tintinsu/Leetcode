class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0) return 0;
        
        int a0=0, a1=n-1;
        while(a0+1<a1){
            int am=(a0+a1)/2;
            if(A[am]==target) return am;
            if(A[am]<target)
                a0=am;
            else
                a1=am;
        }
        
        if(target<=A[a0])
            return a0;
        else if(target<=A[a1])
            return a1;
        else
            return a1+1;
    }
};