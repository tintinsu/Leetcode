class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // special
        int ns=0, np=0, np_star=0;
        while(s[ns]) ns++;
        while(p[np]){
            if(p[np]=='*') np_star++;
            np++;
        }
        if(np-2*np_star > ns) return false;
        
        // 2D DP
        vector<vector<bool>> v(ns+1, vector<bool>(np+1, false));
        for(int i=0;i<=ns;i++){
            for(int j=0;j<=np;j++){
                if(i==0 && j==0) {v[i][j]=true; continue;}
                if(i==0) {if(p[j-1]=='*') v[i][j]=v[i][j-1]||v[i][j-2];continue;}
                if(j==0) {continue;}
                // single equal
                if(p[j-1]=='.'||s[i-1]==p[j-1]) {v[i][j]=v[i-1][j-1];continue;}
                // star
                if(p[j-1]=='*'){
                    v[i][j]=v[i][j-1]||v[i][j-2];
                    if(v[i][j]) continue;
                    if(p[j-2]=='.'||s[i-1]==p[j-2]) v[i][j]=v[i-1][j];
                }
            }
        }
        
        // return
        return v[ns][np];
    }
};