class Solution {
public:
    int maxArea(vector<int> &height) {
        // special
        if(height.size()<=1) return 0;
        
        // loop
        int l=0, r=height.size()-1;
        int max_val = (r-l)*min(height[l], height[r]);
        while(l<r){
            // set the next one
            if(height[l] < height[r]){
                l++;
            }else if(height[r] < height[l]){
                r--;
            }else{
                l++;
                r--;
            }
            
            // update the max
            if(l<r) max_val = max(max_val, (r-l)*min(height[l], height[r]));
        }
        
        // return
        return max_val;
    }
};