class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        
        // search for rows
        int a0=0, a1=m-1, am;
        while(a0+1<a1){
            am=(a0+a1)/2;
            if(matrix[am][0]==target) return true;
            if(matrix[am][0]<target)
                a0=am;
            else
                a1=am;
        }
        if(target>=matrix[a1][0])
            am=a1;
        else if(target>=matrix[a0][0])
            am=a0;
        else 
            return false;
        
        // search for column
        int b0=0, b1=n-1, bm;
        while(b0+1<b1){
            bm = (b0+b1)/2;
            if(matrix[am][bm]==target) return true;
            if(matrix[am][bm]<target)
                b0=bm;
            else
                b1=bm;
        }
        return (target==matrix[am][b0] || target==matrix[am][b1]);
    }
};