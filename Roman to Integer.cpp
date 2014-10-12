class Solution {
public:
    int romanToInt(string s) {
        // intialization
        int val = 0;
        map<char,int>ma;
        ma['I']=1;
        ma['V']=5;
        ma['X']=10;
        ma['L']=50;
        ma['C']=100;
        ma['D']=500;
        ma['M']=1000;
        
        // loop
        for(int i=0;i+1<s.size();i++){
            if(ma[s[i]]<ma[s[i+1]])
                val -= ma[s[i]];
            else
                val += ma[s[i]];
        }
        val += ma[s[s.size()-1]];
        
        // return
        return val;
    }
};