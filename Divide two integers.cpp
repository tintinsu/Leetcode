class Solution {
public:
    int divide(int dividend, int divisor) {
        // special
        if(dividend==0 || divisor==0) return 0;
        bool isPos=(dividend>0&&divisor>0 || dividend<0&&divisor<0)?true:false;
        long long y=abs((long long)dividend), x=abs((long long)divisor);
        if(x==1) return isPos?y:-y;
        if(y<x) return 0;
        
        // general
        int n=0;
        while(y>=pow(x,n+1.0)) n++;
        int ret=0;
        while(y>=x){
            if(y>=pow(x,n*1.0)){
                y-=pow(x,n*1.0);
                ret+=pow(x,n-1.0);
            }else{
                n--;
            }
        }
        
        // return with sign
        return isPos?ret:-ret;
    }
};