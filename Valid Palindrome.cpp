class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int start=0, end=n-1;
        while(1){
            while(start<end && !isalnum(s[start])) start++;
            while(end>start && !isalnum(s[end])) end--;
            if(start >= end) return true;
            if(tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
    }
};