class Solution {
public:
    vector<vector<int> >ret;
    vector<vector<int> > permute(vector<int> &num) {
        ret.clear();
        if(num.size()==0) return ret;
        
        vector<bool> sign(num.size(), false);
        vector<int> v;
        rec_fn(num, sign, v);
        return ret;
    }
    
    void rec_fn(vector<int> &num, vector<bool>sign, vector<int>v){
        if(v.size() == num.size()) {
            ret.push_back(v);
            return;
        }
        
        for(int i=0;i<sign.size();i++){
            if(!sign[i]){
                sign[i]=true;
                vector<int> vec=v;
                vec.push_back(num[i]);
                rec_fn(num,sign,vec);
                sign[i]=false;
            }
        }
    }
};