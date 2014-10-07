class Solution {
public:
    int jump(int A[], int n) {
        vector<int>cnt(n,0);
        int max_pos=0;
        
        if(n==0||n==1) return 0;
        for(int i=0;i<n;i++){
            if(i==0 || cnt[i]>0){
                if(i+A[i]>=n-1) return cnt[i]+1;
                for(int j=max_pos+1;j<=i+A[i];j++) cnt[j]=cnt[i]+1;
                max_pos = max(max_pos,i+A[i]);
            }
        }
        return cnt[n-1];
    }
};