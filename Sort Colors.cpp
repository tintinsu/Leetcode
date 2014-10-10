class Solution {
public:
    void sortColors(int A[], int n) {
        int i=-1, j=0, k=n;
        while(j<k){
            if(A[j]==0){
                int tmp = A[++i];
                A[i] = A[j];
                A[j++] = tmp;
            }else if(A[j]==1){
                j++;
            }else if(A[j]==2){
                int tmp=A[--k];
                A[k] = A[j];
                A[j] = tmp;
            }
        }
    }
};