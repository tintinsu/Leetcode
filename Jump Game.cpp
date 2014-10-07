class Solution {
public:
    bool canJump(int A[], int n) {
        vector<bool>label(n,false);
        label[0] = true;
        int max_pos = 0;
        
        for(int i=0;i<n;i++){
            if(label[i]){
                if(i + A[i] >= n-1) return true;
                for(int j=max_pos+1; j<=i+A[i]; j++) label[j]=true;
                max_pos = max(max_pos, i+A[i]);
            }
        }
        return label[n-1];
    }
};