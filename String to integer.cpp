class Solution {
public:
    int atoi(const char *str) {
        // white space
        while(*str && *str==' ') str++;
        // sign
        bool isPos = true;
        if(*str=='-' || *str=='+'){
            if(*str=='-') isPos = false;
            str++;
        }
        
        // save into string
        string numstr;
        while(*str && isdigit(*str)){
            numstr.append(1, *str);
            str++;
        }
        
        // out of boundary 1
        if(numstr.size()>10) return isPos?INT_MAX:INT_MIN;

        // out of boudnar 2
        if(numstr.size()==10){
            if(isPos && numstr.compare("2147483647")>=0) return INT_MAX;
            if(!isPos && numstr.compare("2147483648")>=0) return INT_MIN;
        }
        
        // convert into an integer
        int val=0;
        for(int i=0;i<numstr.size();i++){
            val = val*10 + numstr[i] - '0';
        }
        // return with sign
        return isPos?val:-val;
    }
};