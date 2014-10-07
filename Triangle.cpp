class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int nLevels = triangle.size();
        vector<int>bk = triangle[nLevels-1];
        for(int i=nLevels-2; i>=0; i--){
            for(int j=0;j<triangle[i].size();j++){
                bk[j] = triangle[i][j] + min(bk[j], bk[j+1]);
            }
        }
        return bk[0];
    }
};