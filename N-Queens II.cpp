class Solution {
public:
    int ret;
    int totalNQueens(int n) {
        ret = 0;
        
        vector<bool>col(n,false);
        vector<bool>plus(2*n-1, false);
        vector<bool>minus(2*n-1, false);
        rec_fn(0,n,col,plus,minus);
        return ret;
    }
    
    void rec_fn(int r, int n, vector<bool>col, vector<bool>plus, vector<bool>minus){
        if(r==n){    
            ret++;
            return;
        }
        
        // general
        for(int i=0;i<n;i++){
            if(col[i] || plus[r+i] || minus[r-i+n-1]) continue;
            
            // set
            col[i] = true;
            plus[r+i] = true;
            minus[r-i+n-1] = true;
            // recursive
            rec_fn(r+1,n,col,plus,minus);
            // reset
            col[i] = false;
            plus[r+i] = false;
            minus[r-i+n-1] = false;
        }
    }
};