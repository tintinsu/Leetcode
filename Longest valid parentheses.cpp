class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>ssta;
        stack<int>ista;
        ista.push(-1);
        
        for(int i=0;i<s.size();i++){
            if(s[i]==')'&&!ssta.empty()&&ssta.top()=='('){
                ssta.pop();
                ista.pop();
            }else{
                ssta.push(s[i]);
                ista.push(i);
            }
        }
        ista.push(s.size());
        
        int best=0;
        while(ista.top()!=-1){
            int top = ista.top();
            ista.pop();
            if(top-ista.top()-1 > best) best = top-ista.top()-1;
        }
        return best;
    }
};