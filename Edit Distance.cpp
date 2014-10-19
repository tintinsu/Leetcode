class Solution {
public:
	/* sol_1: O(mn) in space */
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> opt(n1+1, vector<int>(n2+1, 0));
        
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i==0 && j==0) continue;
                if(i==0) {opt[i][j]=opt[i][j-1]+1; continue;}
                if(j==0) {opt[i][j]=opt[i-1][j]+1; continue;}
                char ch1=word1[i-1], ch2=word2[j-1];
                if(ch1==ch2){
                    opt[i][j]=opt[i-1][j-1];
                }else{
                    opt[i][j]=1+min(min(opt[i-1][j-1],opt[i-1][j]),opt[i][j-1]);
                }
            }
        }
        return opt[n1][n2];
    }

	/* sol_2: O(2xn) in space */
    int minDistance_2(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> opt(2, vector<int>(n2+1, 0));
        
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i==0 && j==0) continue;
                int row = i%2;
                if(i==0) {opt[row][j]=opt[row][j-1]+1; continue;}
                if(j==0) {opt[row][j]=opt[1-row][j]+1; continue;}
                char ch1=word1[i-1], ch2=word2[j-1];
                if(ch1==ch2){
                    opt[row][j]=opt[1-row][j-1];
                }else{
                    opt[row][j]=1+min(min(opt[1-row][j-1],opt[1-row][j]),opt[row][j-1]);
                }
            }
        }
        return opt[n1%2][n2];
    }
};