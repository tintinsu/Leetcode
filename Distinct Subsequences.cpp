class Solution {
public:
    int numDistinct(string S, string T) {
        // special case
        if(T.size() > S.size()) return 0;
        
        // 2D DP
        int m=T.size(), n=S.size();
        vector<vector<int>> v(m+1, vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){v[i][j]=1;continue;}
                if(i<=j){
                    v[i][j] = v[i][j-1];
                    if(T[i-1]==S[j-1]) v[i][j]+=v[i-1][j-1];
                }
            }
        }
        // return
        return v[m][n];
    }
};