class Solution {
public:
    /*original solution*/
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
    
    /*updated solution: for the new return type*/
    int strStr(char *haystack, char *needle) {
        if(!*haystack && !*needle) return 0;
        if(!*haystack) return -1;
        if(!*needle) return 0;
        
        int idx=0;
        while(*(haystack+idx)){
            if(*(haystack+idx) == *needle){
                int j=0;
                while(*(haystack+idx+j) && *(needle+j) && *(haystack+idx+j) == *(needle+j)) j++;
                if(!*(needle+j)) return idx;
                if(!*(haystack+idx+j)) return -1;
            }
            idx++;
        }
        return -1;
    }
};
