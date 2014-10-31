class Solution {
public:
    int sqrt(int x) {
        if(x<=0) return 0;
        if(x==1) return 1;
        long long l=1, r=x;
        while(l+1<r){
            long long m=(l+r)/2;
            if(m*m == x) return m;
            if(m*m > x){
                r = m;
            }else{
                l = m;
            }
        }
        if(r*r <= x) return r;
        if(l*l <= x) return l;
    }
};