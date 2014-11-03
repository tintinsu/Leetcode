class Solution {
public:
	// sol_1: dfs
    void solve_1(vector<vector<char>> &board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        
        // check with DFS
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1||board[i][j]=='O') dfs(i,j,board);
            }
        }
        
        // change Y into X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y') board[i][j]='O';
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
    
    void dfs(int r, int c, vector<vector<char>> &board){
        int m=board.size();
        int n=board[0].size();
        
        // judge other cases
        if(r<0 || c<0 || r==m || c==n) return;
        if(board[r][c]=='X' || board[r][c]=='Y') return;
        
        // assume [r,c] position is 'O' now
        board[r][c]='Y';
        dfs(r-1,c,board);
        dfs(r+1,c,board);
        dfs(r,c-1,board);
        dfs(r,c+1,board);
    }

	// sol_2: bfs
    void solve(vector<vector<char>> &board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        
        // bfs for O on border
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&board[i][j]=='O') {
                    queue<pair<int,int>>qu;
                    qu.push(make_pair(i,j));
                    while(!qu.empty()){
                        int r0=qu.front().first;
                        int c0=qu.front().second;
                        qu.pop();
                        if(board[r0][c0]=='Y') continue;
                        
                        board[r0][c0]='Y';
                        if(r0>0 && board[r0-1][c0]=='O') qu.push(make_pair(r0-1, c0));
                        if(c0>0 && board[r0][c0-1]=='O') qu.push(make_pair(r0, c0-1));
                        if(r0+1<m && board[r0+1][c0]=='O') qu.push(make_pair(r0+1, c0));
                        if(c0+1<n && board[r0][c0+1]=='O') qu.push(make_pair(r0, c0+1));
                    }
                }
            }
        }
        
        // flip Y into O; flip O into X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};