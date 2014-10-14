class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // special case
        vector<int>ret;
        if(S.size()==0 || L.size()==0) return ret;
        int n=S.size(), m=L[0].size(), nWords=L.size();
        
        // count the word list
        map<string,int>ma;
        for(int i=0;i<L.size();i++) ma[L[i]]++;
        
        // loop over positions
        for(int i=0;i<n-m*nWords+1;i++){
            map<string,int>copy;
            bool sign = true;
            for(int j=0;j<nWords;j++){
                string word = S.substr(i+j*m, m);
                if(ma.find(word)==ma.end() || copy[word]==ma[word]) {sign=false; break;}
                copy[word]++;
            }
            if(sign) ret.push_back(i);
        }
        
        // return
        return ret;
    }
};