class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        ret.clear();
        if(S.size()==0) return ret;
        
        // sort
        sort(S.begin(), S.end());
        vector<int>cnt{1};
        for(int i=1;i<S.size();){
            if(S[i]==S[i-1]){
                cnt[cnt.size()-1]++;
                S.erase(S.begin()+i);
            }else{
                cnt.push_back(1);
                i++;
            }
        }
        
        // recursive
        vector<int>v;
        rec_fn(0,S,cnt,v);
        
        // return
        return ret;
    }
    
    void rec_fn(int idx, vector<int> &S, vector<int> &cnt, vector<int>v){
        if(idx==S.size()){
            ret.push_back(v);
            return;
        }
        
        for(int i=0;i<=cnt[idx];i++){
            vector<int>vec=v;
            vec.insert(vec.end(), i, S[idx]);
            rec_fn(idx+1, S, cnt, vec);
        }
    }
};