class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // count
        int ns=0, np=0, np_non_star=0;
        while(s[ns]) ns++;
        while(p[np]){
            if(p[np]!='*') np_non_star++;
            np++;
        }
        if(np_non_star>ns) return false;
        
        // 2D DP
        vector<vector<bool>> v(ns+1, vector<bool>(np+1, false));
        for(int i=0;i<=ns;i++){
            for(int j=0;j<=np;j++){
                if(i==0 && j==0) {v[i][j]=true; continue;}
                if(i==0){
                    v[i][j]=(p[j-1]=='*')?v[i][j-1]:false;
                    continue;
                }
                if(j==0){v[i][j]=false; continue;}
                char chs=s[i-1], chp=p[j-1];
                if(chp=='?'||chs==chp) {v[i][j]=v[i-1][j-1]; continue;}
                if(chp=='*') {v[i][j]=v[i][j-1]||v[i-1][j]; continue;}
            }
        }
        
        // return
        return v[ns][np];
    }
};