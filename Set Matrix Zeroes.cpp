class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // size check
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        
        // 1st row or col check
        bool is_row=false, is_col=false;
        if(matrix[0][0]==0){is_row=true; is_col=true;}
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                is_col=true;
                break;
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                is_row=true;
                break;
            }
        }
        
        // check zeros other than 1st row or col
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        // set 1st row or col except [0,0]
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++) matrix[i][j]=0;
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<m;i++) matrix[i][j]=0;
            }
        }
        
        // set 1st row or col if [0,0] is zero
        if(is_col){for(int i=0;i<m;i++) matrix[i][0]=0;}
        if(is_row){for(int j=0;j<n;j++) matrix[0][j]=0;}
    }
};