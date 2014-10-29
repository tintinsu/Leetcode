class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // special case
        if(start.compare(end)==0) return 1;
        
        // BFS
        int level = 1;
        vector<string> qu1, qu2;
        qu1.push_back(start);
        while(!qu1.empty()){
            // replace
            while(!qu1.empty()){
                string word = qu1[0];
                qu1.erase(qu1.begin());
                for(int i=0;i<word.size();i++){
                    for(char c='a';c<='z';c++){
                        if(c == word[i]) continue;
                        string tmp = word;
                        tmp[i] = c;
                        if(dict.find(tmp)!=dict.end()){
                            if(tmp.compare(end)==0) return level+1;
                            dict.erase(tmp);
                            qu2.push_back(tmp);
                        }
                    }
                }
            }
            // update
            qu1 = qu2;
            qu2.clear();
            level++;
        }
        
        // return
        return 0;
    }
};