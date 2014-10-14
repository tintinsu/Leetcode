class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // special
        string ret;
        if(strs.size()==0 || strs[0].size()==0) return ret;
        
        // loop
        for(int idx=0;idx<strs[0].size();idx++){
            for(int i=1;i<strs.size();i++){
                if(strs[i].size()==idx || strs[i][idx]!=strs[0][idx]) return ret;
            }
            ret.append(1,strs[0][idx]);
        }
        // return
        return ret;
    }
};