class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        
        // append
        vector<string> v(nRows,"");
        int idx=0, isUp=1;
        for(int i=0;i<s.size();i++){
            // fill in this position
            v[idx].append(1,s[i]);
            
            // update next position
            if(isUp){
                idx++;
                if(idx==nRows){
                    isUp=0;
                    idx-=2;
                }
            }else{
                idx--;
                if(idx==-1){
                    isUp=1;
                    idx+=2;
                }
            }
        }
        
        // integrate
        string ret;
        for(int i=0;i<nRows;i++) ret.append(v[i]);
        
        // return
        return ret;
    }
};