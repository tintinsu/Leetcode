class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > combine(int n, int k) {
        ret.clear();
        
        vector<int> v;
        rec_fn(1,n,k,v);
        return ret;
    }
    
    void rec_fn(int k0, int k1, int k, vector<int>v){
        if(k1-k0+1 < k-v.size()) return;
        
        if(v.size() == k) {
            ret.push_back(v);
            return;
        }
        
        for(int i=k0;i<=k1;i++){
            v.push_back(i);
            rec_fn(i+1,k1, k, v);
            v.erase(v.begin()+v.size()-1);
        }
    }
};