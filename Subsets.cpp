class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > subsets(vector<int> &S) {
        ret.clear();
        sort(S.begin(),S.end());
        
        vector<int>v;
        rec_fn(0,S.size()-1,S,v);
        return ret;
    }
    
    void rec_fn(int k0, int k1, vector<int> &S, vector<int>v){
        if(k0>k1){
            ret.push_back(v);
            return;
        }
        
        // not existing
        rec_fn(k0+1, k1, S, v);
        
        // existing
        v.push_back(S[k0]);
        rec_fn(k0+1,k1,S,v);
        v.erase(v.end()-1);
    }
};