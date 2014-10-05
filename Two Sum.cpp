bool compare(pair<int,int>p1, pair<int,int>p2){
    return p1.second < p2.second;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // organize the data
        vector<pair<int,int>> num;
        for(int i=0;i<numbers.size();i++){
            num.push_back(make_pair(i, numbers[i]));
        }
        // sort
        sort(num.begin(), num.end(), compare);
        
        // find the sum
        int s=0, e=num.size()-1;
        while(s<e){
            if(num[s].second + num[e].second == target){
                break;
            }else if(num[s].second + num[e].second < target){
                s++;
            }else{
                e--;
            }
        }
        
        // return: (1) sort index; (2) 1+the result
        vector<int> ret;
        ret.push_back(min(num[s].first, num[e].first)+1);
        ret.push_back(max(num[s].first, num[e].first)+1);
        return ret;
    }
};