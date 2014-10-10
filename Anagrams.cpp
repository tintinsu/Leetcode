bool compare(string c1, string c2){
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    return c1.compare(c2) < 0;
}

class Solution {
public:
	// sol_1: sorting with O(nlgn)
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        if(strs.size()==0) return ret;
        // sort strings
        sort(strs.begin(), strs.end(), compare);
        // output strings
        int label = 0, cnt = 1;
        string s_label = strs[0];
        sort(s_label.begin(), s_label.end());
        for(int i=1;i<strs.size();i++){
            string s_curr = strs[i];
            sort(s_curr.begin(), s_curr.end());
            if(s_label.compare(s_curr)==0){
                if(cnt == 1) ret.push_back(strs[label]);
                ret.push_back(strs[i]);
                cnt++;
            }else{
                label = i;
                cnt = 1;
                s_label = s_curr;
            }
        }
        // return 
        return ret;
    }

	// sol_2: hash table with O(n)
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> ma;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            ma[s].push_back(strs[i]);
        }
        
        vector<string> ret;
        map<string, vector<string>>::iterator it;
        for(it=ma.begin();it!=ma.end();it++){
            if(it->second.size()>1){
                vector<string>tmp = it->second;
                for(int i=0;i<tmp.size();i++) ret.push_back(tmp[i]);
            }
        }
        return ret;
    }
};