class Solution {
public:
    string countAndSay(int n) {
        string str1, str2;
        if(n<=0) return str1;
        str1 = "1";
        for(int i=2;i<=n;i++){
            // count and say
            int idx=1, cnt=1;
            char code=str1[0];
            while(idx<str1.size()){
                if(str1[idx]==str1[idx-1]){
                    cnt++;
                }else{
                    // push
                    str2.append(cntnum2str(cnt));
                    str2.append(1,code);
                    // update
                    code = str1[idx];
                    cnt = 1;
                }
                idx++;
            }
            
            // the last group
            str2.append(cntnum2str(cnt));
            str2.append(1,code);
                    
            // update
            str1 = str2;
            str2.clear();
        }
        return str1;
    }
    
    string cntnum2str(int cnt){    
        string s;
        while(cnt>0){
            s.insert(0,1,cnt%10+'0');
            cnt/=10;
        }
        return s;
    }
};