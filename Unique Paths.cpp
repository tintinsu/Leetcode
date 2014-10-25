class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        
        int ma = max(m,n), na=min(m,n);
        long long ret_num = 1, ret_deno = 1;
        for(int i=1;i<=na-1;i++){
            int num = i+ma-1;
            int deno = i;
            if(num%2==0 && deno%2==0){
                ret_num  *= (long long)(num/2);
                ret_deno *= (long long)(deno/2);
            }else{
                ret_num  *= (long long)num;
                ret_deno *= (long long)deno;
            }
        }
        return ret_num/ret_deno ;
    }
};