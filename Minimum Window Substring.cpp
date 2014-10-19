class Solution {
public:
    string minWindow(string S, string T) {
        // corner case
        if(S.size()==0 || T.size()==0) return "";
        
        // analyze T
        map<char,int> tma;
        for(int i=0;i<T.size();i++) tma[T[i]]++;

        // analyze S
        map<char,int> all;
        for(int i=0;i<S.size();i++) all[S[i]]++;
        map<char,int>::iterator it;
        for(it=tma.begin();it!=tma.end();it++){
            char ch = it->first;
            if(it->second > all[ch]) return "";
        }
        
        // find the first T in S
        int tail=S.size()-1, head=0;
        while(tail>=head){
            char ch = S[tail];
            // more
            if(all[ch]>tma[ch]){
                tail--;
                all[ch]--;
            }else{
                break;
            }
        }
        if(tail<head) return "";
        
        // double pointer move
        string minstr=S.substr(head,tail-head+1);
        while(tail<S.size()){
            // remove
            while(all[S[head]]>tma[S[head]]) {all[S[head]]--;head++;}
            if(tail-head+1<minstr.size()) minstr=S.substr(head,tail-head+1);
            // append
            char curr = S[head];
            tail++;
            while(tail<S.size()){
                all[S[tail]]++;
                if(S[tail]==curr) break;
                tail++;
            }
        }
        
        // return
        return minstr;
    }
};