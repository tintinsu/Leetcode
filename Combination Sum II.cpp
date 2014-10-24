class Solution {
public:
    vector<vector<int> > ret;
    vector<int>cnt;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        ret.clear();
        cnt.clear();
        
        // sort
        if(num.size()==0 || target<=0) return ret;
        sort(num.begin(), num.end());
        
        // analyze
        cnt.push_back(1);
        for(int i=1;i<num.size();){
            if(num[i]==num[i-1]){
                cnt[i-1]++;
                num.erase(num.begin()+i);
            }else{
                cnt.push_back(1);
                i++;
            }
        }
        
        // recursive
        vector<int> v;
        rec_fn(num, 0, v, target);
        
        // return
        return ret;
    }
    
    void rec_fn(vector<int> &num, int idx, vector<int> vec, int target){
        // stop
        if(target==0){
            ret.push_back(vec);
            return;
        }
        if(idx==num.size()) return;
        
        // general
        for(int i=0;i<=min(cnt[idx], target/num[idx]);i++){
            vector<int>v=vec;
            for(int j=0;j<i;j++) v.push_back(num[idx]);
            rec_fn(num,idx+1,v,target-i*num[idx]);
        }
    }
};