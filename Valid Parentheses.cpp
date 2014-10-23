class Solution {
public:
    bool isValid(string s) {
        map<char,char> ma;
        ma[')']='(';
        ma[']']='[';
        ma['}']='{';
        
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(!sta.empty() && sta.top()==ma[s[i]]){
                    sta.pop();
                }else{
                    return false;
                }
            }else{
                sta.push(s[i]);
            }
        }
        if(!sta.empty()) return false;
        return true;
    }
};