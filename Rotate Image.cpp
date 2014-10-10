class Solution {
public:
	// sol_1: matrix rotation
    void rotate(vector<vector<int> > &matrix) {
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(m!=n) return;
        
        // rotate along diagonal
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
        // rotate along vertical mid
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=tmp;
            }
        }
    }

	// sol_2: element rotation
    void rotate_2(vector<vector<int> > &matrix) {
        // check size
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(m!=n) return;
        
        // rotation
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
            }
        }
    }
};