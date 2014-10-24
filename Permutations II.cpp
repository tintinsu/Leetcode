class Solution {
public:
    vector<vector<int> > ret;
    vector<int> cnt;
    int num_elem;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        ret.clear();
        cnt.clear();
        if(num.size()==0) return ret;
        
        // analyze num and cnt
        sort(num.begin(), num.end());
        num_elem = num.size();
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
        vector<int>v;
        rec_fn(num,v);
        
        // return
        return ret;
    }
    
    void rec_fn(vector<int> &num, vector<int> vec){
        if(vec.size()==num_elem){
            ret.push_back(vec);
            return;
        }
        
        for(int i=0;i<num.size();i++){
            if(cnt[i]>0){
                cnt[i]--;
                vector<int>v=vec;
                v.push_back(num[i]);
                rec_fn(num, v);
                cnt[i]++;
            }
        }
    }
};