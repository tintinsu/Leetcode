class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3) return 0;
        sort(num.begin(), num.end());
        int best = num[0]+num[1]+num[2];
        for(int i1=0; i1+2<num.size(); i1++){
            if(i1>0 && num[i1]==num[i1-1]) continue;
            int i2 = i1+1, i3 = num.size()-1;
            while(i2 < i3){
                if(i2>i1+1 && num[i2]==num[i2-1]) {i2++; continue;}
                int sum = num[i1] + num[i2] + num[i3];
                if(abs(sum-target) < abs(best-target)) best = sum;
                if(sum == target){
                    return target;
                }else if(sum < target){
                    i2++;
                }else{
                    i3--;
                }
            }
        }
        return best;
    }
};