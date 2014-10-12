class Solution {
public:
    bool isPalindrome(int x) {
        // border
        if(x<0) return false;
        
        // nDigits
        int n=0;
        while(x >= pow(10.0, n+1)) n++;
        
        // check symmetry
        int i0=0, i1=n;
        while(i0 < i1){
            int d0 = x/(int)pow(10.0, i0)%10;
            int d1 = x/(int)pow(10.0, i1)%10;
            if(d0!=d1) return false;
            
            // update
            i0++;
            i1--;
        }
        
        // return
        return true;
    }
};