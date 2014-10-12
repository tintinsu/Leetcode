class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // check size
        int m=board.size();
        if(m==0) return false;
        int n=board[0].size();
        if(m!=9 || n!=9) return false;
        
        // check each row
        for(int i=0;i<9;i++){
            if(!check(board[i])) return false;
        }
        
        // check each col
        for(int j=0;j<9;j++){
            vector<char>v;
            for(int i=0;i<9;i++) v.push_back(board[i][j]);
            if(!check(v)) return false;
        }
        
        // check each box
        for(int i_large=0; i_large<3; i_large++){
            for(int j_large=0; j_large<3; j_large++){
                vector<char>v;
                for(int i=3*i_large; i<3*i_large+3; i++){
                    for(int j=3*j_large; j<3*j_large+3; j++){
                        v.push_back(board[i][j]);
                    }
                }
                if(!check(v)) return false;
            }
        }
        
        return true;
    }
    
    bool check(vector<char>v){
        vector<char>ex(v.size(), false);
        for(int i=0;i<v.size();i++){
            if(v[i]=='.') continue;
            if(v[i]<'1'||v[i]>'9') return false;
            if(ex[v[i]-'1']) return false;
            ex[v[i]-'1'] = true;
        }
        return true;
    }
};