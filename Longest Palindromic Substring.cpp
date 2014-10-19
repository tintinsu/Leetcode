class Solution {
public:
    string longestPalindrome(string s) {
        // special
        if(s.size()==0) return "";
        
        // odd
        string ret(s.substr(0,1));
        for(int i=1;i+ret.size()/2+1<s.size();i++){
            // check this
            int il=i-1, ir=i+1;
            while(il>=0 &&  ir<s.size()){
                if(s[il]==s[ir]){
                    il--;
                    ir++;
                }else{
                    break;
                }
            }
            // check for more
            if(ir-il-1>ret.size()) ret=s.substr(il+1,ir-il-1);
        }
        
        // even
        for(int i=ret.size()/2;i+(1+ret.size())/2<s.size();i++){
            // check this
            int il=i, ir=i+1;
            while(il>=0 && ir<s.size()){
                if(s[il]==s[ir]){
                    il--;
                    ir++;
                }else{
                    break;
                }
            }
            // check for more
            if(ir-il-1>ret.size()) ret=s.substr(il+1,ir-il-1);
        }
        
        // return
        return ret;
    }
};