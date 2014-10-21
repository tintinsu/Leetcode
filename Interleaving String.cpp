class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // special
        if(s1.size() + s2.size() != s3.size()) return false;
        
        // DP 2D
        int m=s1.size(), n=s2.size();
        vector<vector<bool>> v(m+1, vector<bool>(n+1, false));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0) {v[i][j]=true; continue;}
                if(i==0){
                    if(s2[j-1]==s3[j-1]) v[i][j]=v[i][j-1];
                    continue;
                }
                if(j==0){
                    if(s1[i-1]==s3[i-1]) v[i][j]=v[i-1][j];
                    continue;
                }
                if(s1[i-1]==s3[i+j-1]) v[i][j] = v[i][j] || v[i-1][j];
                if(s2[j-1]==s3[i+j-1]) v[i][j] = v[i][j] || v[i][j-1];
            }
        }
        // return
        return v[m][n];
    }
};