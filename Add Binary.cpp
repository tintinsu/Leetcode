class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int ia=a.size()-1, ib=b.size()-1, cin=0;
        while(cin>0 || ia>=0 || ib>=0){
            int tmp=cin;
            if(ia>=0) tmp+=(a[ia--]-'0');
            if(ib>=0) tmp+=(b[ib--]-'0');
            cin=tmp/2;
            ret.insert(0,1,tmp%2+'0');
        }
        return ret;
    }
};