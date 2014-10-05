class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >ret;
        if(num.size()<4) return ret;
        
        // sort
        sort(num.begin(), num.end());
        
        // search
        for(int i1=0;i1+3<num.size();i1++){
            if(i1>0 && num[i1]==num[i1-1]) continue;
            for(int i2=i1+1; i2+2<num.size(); i2++){
                if(i2>i1+1 && num[i2]==num[i2-1]) continue;
                int i3=i2+1, i4=num.size()-1;
                while(i3<i4){
                    if(i3>i2+1 && num[i3]==num[i3-1]) {i3++; continue;}
                    int sum=num[i1]+num[i2]+num[i3]+num[i4];
                    if(sum == target){
                        int arr[4] = {num[i1], num[i2], num[i3], num[i4]};
                        vector<int>v(arr, arr+4);
                        ret.push_back(v);
                        i3++; i4--;
                    }else if(sum < target){    
                        i3++;
                    }else{
                        i4--;
                    }
                }
            }
        }
        
        // return
        return ret;
    }
};