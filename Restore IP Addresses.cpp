class Solution {
public:
    vector<string> ret;
    vector<string> restoreIpAddresses(string s) {
        ret.clear();
        
        string ip;
        rec(s,0,0,ip);
        return ret;
    }
    
    void rec(string s, int cWords, int idx, string word){
        // stop
        if(idx==s.size() || cWords==4) {
            if(idx==s.size() && cWords==4) {
                word.erase(word.size()-1,1);
                ret.push_back(word);
            }
            return;
        }
        
        // general
        if(idx<s.size()){
            string add1=word;
            add1.append(1,s[idx]);
            add1.append(1,'.');
            rec(s,cWords+1,idx+1,add1);
        }
        
        if(idx+1<s.size() && s.substr(idx,2).compare("10")>=0 && s.substr(idx,2).compare("99")<=0){
            string add2=word;
            add2.append(s.substr(idx,2));
            add2.append(1,'.');
            rec(s,cWords+1,idx+2,add2);
        }
        
        if(idx+2<s.size() && s.substr(idx,3).compare("100")>=0 && s.substr(idx,3).compare("255")<=0){
            string add3=word;
            add3.append(s.substr(idx,3));
            add3.append(1,'.');
            rec(s,cWords+1,idx+3,add3);
        }
    }
};