class Solution {
public:
    vector<vector<string> > ret;
    vector<vector<string> > solveNQueens(int n) {
        ret.clear();
        string s;
        vector<string> board(n, s.append(n,'.'));
        vector<bool>col(n, false);
        vector<bool>plus(2*n-1, false);
        vector<bool>minus(2*n-1, false);
        rec_fn(board, 0, n, col, plus, minus);
        return ret;
    }
    
    void rec_fn(vector<string>&board, int r, int n, vector<bool>col, vector<bool>plus, vector<bool>minus){
        // special case
        if(r==n){
            ret.push_back(board);
            return;
        }
        
        // general case
        for(int i=0;i<n;i++){
            if(col[i] || plus[i+r] || minus[i-r+n-1]) continue;
            
            // set
            board[r][i]='Q';
            col[i] = true;
            plus[i+r] = true;
            minus[i-r+n-1] = true;
            
            // recursive
            rec_fn(board, r+1, n, col, plus, minus);
            
            // reset
            board[r][i]='.';
            col[i] = false;
            plus[i+r] = false;
            minus[i-r+n-1] = false;
        }
        
    }
};