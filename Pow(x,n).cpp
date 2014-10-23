class Solution {
public:
    double pow(double x, int n) {
        bool isPos=(n>=0)?true:false;
        long long n_pos = abs((long long)n);
        
        // discuss x
        if(n_pos ==0) return 1.0;
        if(x==0.0||x==1.0) return x;
        if(x==-1.0) return n_pos%2==0?-x:x;
        
        // general case
        double ret=pow(x,n_pos/2);
        ret*=ret;
        if(n_pos%2==1) ret*=x;
        
        // return
        return isPos?ret:1/ret;
    }
};