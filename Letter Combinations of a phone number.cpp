class Solution {
public:
    vector<string> ret;
    map<char,string>ma;
    vector<string> letterCombinations(string digits) {
        ret.clear();
        
        // mapping
        ma.clear();
        ma['0']=" ";
        ma['2']="abc";
        ma['3']="def";
        ma['4']="ghi";
        ma['5']="jkl";
        ma['6']="mno";
        ma['7']="qprs";
        ma['8']="tuv";
        ma['9']="wxyz";
        
        // recursive
        string str;
        rec(digits,str,0);
        
        return ret;
    }
    
    void rec(string digits,string str,int idx){
        // stop
        if(idx==digits.size()){
            ret.push_back(str);
            return;
        }
        
        // recursive
        char code = digits[idx];
        if(code=='1'||code=='*'||code=='#'){
            rec(digits,str,idx+1);
        }else{
            string candi=ma[code];
            for(int i=0;i<candi.size();i++){
                string s=str;
                s.append(1,candi[i]);
                rec(digits,s,idx+1);
            }
        }
    }
};