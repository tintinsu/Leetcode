class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        string s;
        return rec_fn(n, k, v, s);
    }
    
    string rec_fn(int n, int k, vector<int>&v, string s){
        if(n==0) return s;
        
        // general case
        int n_1_factor = 1;
        for(int i=2;i<=n-1;i++) n_1_factor*=i;
        int idx = (k-1)/n_1_factor;
        s.append(1, v[idx]+'0');
        v.erase(v.begin()+idx);
        return rec_fn(n-1, k-idx*n_1_factor, v, s);
    }
};