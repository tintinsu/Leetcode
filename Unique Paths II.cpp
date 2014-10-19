class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> opt(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {opt[i][j]=1;continue;}
                if(obstacleGrid[i][j]==0){
                    if(i==0) {opt[i][j]=opt[i][j-1]; continue;}
                    if(j==0) {opt[i][j]=opt[i-1][j]; continue;}
                    opt[i][j] = opt[i-1][j] + opt[i][j-1];
                }
            }
        }
        return opt[m-1][n-1];
    }
};