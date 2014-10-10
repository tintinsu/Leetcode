class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int prev_prev = 1, curr=0;
        int prev = (s[0]=='0'?0:1);
        for(int i=1;i<s.size();i++){
            // assign
            int val_d1 = s[i] - '0';
            int val_d2 = (s[i-1]-'0')*10 + (s[i]-'0');
            curr = (s[i]=='0'?0:prev) + ((val_d2>=10&&val_d2<=26)?prev_prev:0);
            
            // update
            prev_prev = prev;
            prev = curr;
        }
        
        // return
        return prev;
    }
};