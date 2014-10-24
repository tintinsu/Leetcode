class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        rec_fn(board, 0, 0);
    }
    
    bool rec_fn(vector<vector<char> > &board, int row, int col){
        if(row==9 && col==0) return true;
        
        // next position
        int row_next = row+(col+1)/9, col_next = (col+1)%9;
        // if empty: discuss
        if(board[row][col]=='.'){
            for(int i=1;i<=9;i++){
                if(!isValOK(board, row,col,i)) continue;
                board[row][col] = '0'+i;
                bool isOK = rec_fn(board, row_next, col_next);
                if(isOK) return true;
            }
            
            board[row][col] = '.';
            return false;
        }else{
            return rec_fn(board, row_next, col_next);
        }
    }
    
    bool isValOK(vector<vector<char>> &board, int r, int c, int val){
        // check each row
        for(int i=0;i<9;i++){
            if(i==c) continue;
            if(board[r][i]=='0'+val) return false;
        }
        
        // check each col
        for(int i=0;i<9;i++){
            if(i==r) continue;
            if(board[i][c]=='0'+val) return false;
        }
        
        // check each box
        int r_large=r/3, c_large=c/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(3*r_large+i==r && 3*c_large+j==c) continue;
                if(board[3*r_large+i][3*c_large+j]=='0'+val) return false;
            }
        }
        
        return true;
    }
};