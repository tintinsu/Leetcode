class Solution {
public:
    /*method 1*/
    int lengthOfLongestSubstring(string s) {
        // special case
        if(s.size()<=1) return s.size();
        
        // iterative
        int max_val=1, start=0;
        vector<int>hash(256,-1);
        hash[s[0]]=0;
        for(int i=1;i<s.size();i++){
            if(hash[s[i]]==-1){
                // update hash
                hash[s[i]] = i;
            }else{
                // remove
                int end = hash[s[i]];
                for(int j=start;j<=end;j++) hash[s[j]]=-1;
                // update start
                start = end+1;
                hash[s[i]]=i;
            }
            
            // update max
            max_val = max(max_val, i-start+1);
        }
        // return largest
        return max_val;
    }
    
    /*method 2*/
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int st=0, ed=0, max_len=0;
        unordered_set<char> uset;
        while(ed < s.size()){
            while(uset.find(s[ed])==uset.end()){
                max_len = max(max_len, ed-st+1);
                uset.insert(s[ed]);
                ed++;
                if(ed == s.size()) return max_len;
            }
            
            while(s[st]!=s[ed]){
                uset.erase(s[st++]);
            }
            uset.erase(s[st++]);
        }
    }
};
