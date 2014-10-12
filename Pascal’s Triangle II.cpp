class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<0){
            vector<int> ret;
            return ret;
        }
        vector<int> ret(rowIndex+1,0);
        ret[0]=1;
        
        for(int k=1;k<=rowIndex;k++){
            for(int i=k;i>0;i--){
                if(i==k) {ret[i]=1;continue;}
                ret[i]+=ret[i-1];
            }
        }
        return ret;
    }
};