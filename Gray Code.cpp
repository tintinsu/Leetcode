class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if(n==0){
            ret.push_back(0);
            return ret;
        }
        
        ret.push_back(0);
        ret.push_back(1);
        for(int j=2;j<=n;j++){
            int len = ret.size();
            for(int i=len-1;i>=0;i--) ret.push_back(ret[i]+(1<<(j-1)));
        }
        return ret;
    }
};