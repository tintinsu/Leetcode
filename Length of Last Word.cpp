class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!*s) return 0;
        int idx = 0;
        while(s[idx+1]) idx++;
        while(s[idx]==' '){
            if(idx == 0) return 0;
            idx--;
        }
        int i = idx;
        while(i>=0 && isalpha(s[i])) i--;
        return idx - i;
    }
};