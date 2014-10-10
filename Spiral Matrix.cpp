class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int>ret;
        int m=matrix.size();
        if(m==0) return ret;
        int n=matrix[0].size();
        
        for(int i=0;i<(min(m,n)+1)/2;i++){
            int row_min = i, row_max = m-1-i;
            int col_min = i, col_max = n-1-i;
            // first row
            for(int j=col_min;j<col_max; j++) ret.push_back(matrix[row_min][j]);
            // last col
            for(int j=row_min;j<=row_max;j++) ret.push_back(matrix[j][col_max]);
            // last row
            if(col_min==col_max || row_min==row_max) break;
            for(int j=col_max-1;j>=col_min;j--) ret.push_back(matrix[row_max][j]);
            // first col
            for(int j=row_max-1;j>row_min;j--) ret.push_back(matrix[j][col_min]);
        }
        
        // return
        return ret;
    }
};