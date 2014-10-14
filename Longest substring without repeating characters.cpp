class Solution {
public:
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
};