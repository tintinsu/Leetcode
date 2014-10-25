class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n=digits.size(), cin=1;
        for(int i=n-1;i>=0;i--){
            int sum = cin + digits[i];
            digits[i] = sum%10;
            cin = sum/10;
        }
        if(cin>0) digits.insert(digits.begin(), cin);
        return digits;
    }
};