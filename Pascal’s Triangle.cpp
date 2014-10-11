class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows<=0) return ret;
        
        for(int i=0;i<numRows;i++){
            vector<int>v;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) {v.push_back(1);continue;}
                v.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            ret.push_back(v);
        }
        return ret;
    }
};