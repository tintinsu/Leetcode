class Solution {
public:
    bool isNumber(const char *s1) {
        char *s = new char (strlen(s1)+1);
        strcpy(s, s1);
        // zero or multiple words
        char *w1 = strtok(s, " ");
        if(w1==NULL) return false;
        char *w2 = strtok(NULL, " ");
        if(w2!=NULL)  return false;
        
        // analyze e
        if(*w1=='e') return false;
        int cnt_e = 0, i=0;
        for(;*(w1+i);i++){
            if(*(w1+i) == 'e') cnt_e++;
            if(cnt_e>1) return false;
        }
        if(*(w1+i-1)=='e') return false;
        
        // separate by e
        char *e1 = strtok(w1, "e");
        char *e2 = strtok(NULL, "e");
        char *e3 = strtok(NULL, "e");
        if(e3!=NULL || e1==NULL) return false;
        if(!isnum_fn(e1, 1)) return false;
        if(e2!=NULL && !isnum_fn(e2, 2)) return false;
        return true;
    }
    
    bool isnum_fn(char *num, int type){
        int cnt_dot = 0, cnt_num = 0, idx = 0;
        while(*(num+idx)){
            char pos = *(num+idx);
            // sign
            if(idx>0 && (pos=='+'||pos=='-')) return false;
            if(pos=='+'||pos=='-') {idx++; continue;}
            
            // dot
            if(type == 1){
                if(cnt_dot==1 && pos=='.') return false;
                if(pos=='.') {cnt_dot++; idx++; continue;}
            }else if(pos=='.') return false;
            
            // num
            if(pos<'0'||pos>'9') return false;
            cnt_num++;
            idx++;
        }
        if(cnt_num==0) return false;
        return true;
    }
};