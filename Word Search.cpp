class Solution {
public:
    vector<vector<char> > board;
    bool exist(vector<vector<char> > &board1, string word) {
        board = board1;
        // special
        int m = board.size();
        if(m==0) return false;
        int n = board[0].size();
        if(m*n < word.size() || word.size()==0) return false;
        
        // recursive
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> label(m, vector<bool>(n, false));
                    if(dfs(i,j,word,label, 0)) return true;
                }
            }
        }
        
        // return
        return false;
    }
    
    bool dfs(int row, int col, string word, vector<vector<bool>> &label, int idx){   
        // general
        if(board[row][col] != word[idx]) return false;
        label[row][col] = true;
        
        if(idx+1 == word.size()) return true;
        
        // up
        if(row>=1 && !label[row-1][col] && dfs(row-1,col,word,label,idx+1)) return true;
        
        // down
        if(row+1<board.size() && !label[row+1][col] && dfs(row+1,col,word,label,idx+1)) return true;
        
        // left
        if(col>=1 && !label[row][col-1] && dfs(row,col-1,word,label,idx+1)) return true;
        
        // right
        if(col+1<board[0].size() && !label[row][col+1] && dfs(row,col+1,word,label,idx+1)) return true;
        
        label[row][col] = false;
        return false;
    }
};