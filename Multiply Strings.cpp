class Solution {
public:
    string multiply(string num1, string num2) {
        // special cases
        if(num1.compare("0")==0 || num2.compare("0")==0) return "0";
        
        // general
        int n2=num2.size();
        string sum="0";
        for(int i=n2-1;i>=0;i--){
            string mul = strmul(num1, num2[i]);
            sum = strsum(sum, mul, n2-1-i);
        }
        
        // return
        return sum;
    }
    
    string strmul(string num, char mul){
        if(mul=='0') return "0";
        string ret;
        int cin=0;
        for(int i=num.size()-1;i>=0;i--){
            int sum = (mul-'0')*(num[i]-'0') + cin;
            cin = sum/10;
            ret.insert(0,1,sum%10+'0');
        }
        if(cin>0) ret.insert(0,1,cin+'0');
        return ret;
    }
    
    string strsum(string sum, string val, int idx){
        if(val.compare("0")==0) return sum;
        val.append(idx,'0');
        if(sum.compare("0")==0) return val;
        string ret;
        int cin=0, i1=sum.size()-1, i2=val.size()-1;
        while(cin>0 || i1>=0 || i2>=0) {
            int tmp = cin;
            if(i1>=0) {tmp+=(sum[i1]-'0');i1--;}
            if(i2>=0) {tmp+=(val[i2]-'0');i2--;}
            cin = tmp/10;
            ret.insert(0,1,tmp%10+'0');
        }
        return ret;
    }
};