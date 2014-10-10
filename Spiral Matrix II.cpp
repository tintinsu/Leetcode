class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // initialization and border
        vector<vector<int>> ret(n, vector<int>(n,0));
        if(n==0) return ret;
        
        // loop over positions
        int num=1;
        for(int i=0;i<(n+1)/2;i++){
            int row_min=i, row_max=n-1-i;
            int col_min=i, col_max=n-1-i;
            // first row
            for(int j=col_min;j<col_max;j++) ret[row_min][j]=(num++);
            // last col
            for(int j=row_min;j<=row_max;j++) ret[j][col_max]=(num++);
            // single checking
            if(row_min==row_max || col_min==col_max) break;
            // last row
            for(int j=col_max-1;j>=col_min;j--) ret[row_max][j]=(num++);
            // first col
            for(int j=row_max-1;j>row_min;j--) ret[j][col_min]=(num++);
        }
        
        // return
        return ret;
    }
};