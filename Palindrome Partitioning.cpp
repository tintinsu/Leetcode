class Solution {
public:
    vector<vector<string>> partition(string s) {
        return rec_fn(s, 0);
    }
    
    vector<vector<string>> rec_fn(string s, int idx){
        vector<vector<string>> ret;
        
        for(int i=idx;i<s.size();i++){
            string sub=s.substr(idx, i-idx+1);
            if(isPalin(sub)){
                if(i+1==s.size()){
                    vector<string>v;
                    v.push_back(sub);
                    ret.push_back(v);
                }else{
                    vector<vector<string>> tail = rec_fn(s, i+1);
                    for(int k=0;k<tail.size();k++){
                        tail[k].insert(tail[k].begin(), sub);
                        ret.push_back(tail[k]);
                    }
                }
            }
        }
        
        // return 
        return ret;
    }
    
    bool isPalin(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
};