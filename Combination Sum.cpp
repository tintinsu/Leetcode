class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        ret.clear();
        
        // sort the candi vector
        sort(candidates.begin(), candidates.end());
        
        // take the unique ones
        for(int i=1;i<candidates.size();){
            if(candidates[i]==candidates[i-1]){
                candidates.erase(candidates.begin()+i);
            }else{
                i++;
            }
        }
        
        // recursive alg
        vector<int>v;
        rec_fn(candidates, 0, v, target);
        
        // return
        return ret;
    }
    
    void rec_fn(vector<int> &candidates, int idx, vector<int>v, int target){
        // stop case
        if(target==0) {
            ret.push_back(v);
            return;
        }
        if(idx==candidates.size()) return;
        
        
        // general case
        for(int i=0;i<=target/candidates[idx];i++){
            vector<int>vec=v;
            for(int j=0;j<i;j++) vec.push_back(candidates[idx]);
            rec_fn(candidates, idx+1, vec, target-i*candidates[idx]);
        }
    }
};