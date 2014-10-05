class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // border case
        vector<vector<int> > ret;
        if(num.size()<3) return ret;
        
        // sort
        sort(num.begin(), num.end());
        
        // 3sum
        for(int i1=0;i1+2<num.size();i1++){
            if(i1>0 && num[i1]==num[i1-1]) continue;
            int i2=i1+1, i3=num.size()-1;
            while(i2<i3){
                if(i2>i1+1 && num[i2]==num[i2-1]) {i2++;continue;}
                if(num[i1] + num[i2] + num[i3] == 0){
                    vector<int> v;
                    v.push_back(num[i1]);
                    v.push_back(num[i2]);
                    v.push_back(num[i3]);
                    ret.push_back(v);
                    i2++; i3--;
                }else if(num[i1] + num[i2] + num[i3] < 0){
                    i2++;
                }else{
                    i3--;
                }
            }
        }
        
        // return
        return ret;
    }
};