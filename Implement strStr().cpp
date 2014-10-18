class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // special case
        if(!*needle) return haystack;
        if(!*haystack) return NULL;
        
        // general case
        while(*haystack){
            if(*haystack == *needle) {
                int val = isSame(haystack,needle);
                switch(val){
                    case 1:
                        return haystack;
                    case 2:
                        break;
                    case 3:
                        return NULL;
                }
            }
            haystack++;
        }
        
        // final return
        return NULL;
    }
    
    int isSame(char *haystack, char *needle){
        int i=0;
        while(haystack[i] && needle[i]){
            if(haystack[i] != needle[i]) return 2;
            i++;
        }
        if(!needle[i]) return 1;
        return 3;
    }
};