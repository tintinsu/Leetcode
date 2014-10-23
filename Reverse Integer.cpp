class Solution {
public:
    int reverse(int x) {
        long long x_pos = abs((long long) x);
        long long ret = 0;
        while(x_pos > 0){
            int d = x_pos%10;
            x_pos /= 10;
            ret = ret*10 + d;
        }
        return x>=0?ret:-ret;
    }
};