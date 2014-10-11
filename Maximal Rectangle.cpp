class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        if(m==0)return 0;
        int n=matrix[0].size();
        
        int max_area = 0;
        vector<vector<int>> val(m,vector<int>(n,0));
        vector<vector<int>> col=val, row=val;
        // fill in val
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                val[i][j]=matrix[i][j]-'0';
            }
        }
        // construct col and row
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(i==0 || val[i-1][j]==0) {col[i][j]=val[i][j]; continue;}
                if(val[i][j]==0) continue;
                col[i][j] = col[i-1][j]+1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 || val[i][j-1]==0) {row[i][j]=val[i][j]; continue;}
                if(val[i][j]==0) continue;
                row[i][j] = row[i][j-1]+1;
            }
        }
        // count largest area
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(val[i][j]==0) continue;
                int row_val = row[i][j];
                int col_val = col[i][j];
                for(int cnt=0;cnt<row_val;cnt++){
                    col_val=min(col_val, col[i][j-cnt]);
                    max_area = max(max_area, (cnt+1)*col_val);
                }
            }
        }
        // return
        return max_area;
    }
};