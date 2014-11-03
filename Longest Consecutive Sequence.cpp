class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, bool> ma;
        for(int i=0;i<num.size();i++) ma[num[i]]=true;
        int max_all = 0;
        map<int, bool>::iterator it;
        for(it=ma.begin(); it!=ma.end();it++){
            if(it->second){
                int val1 = it->first, val2 = it->first, cnt = 1;
                while(ma.find(val1+1)!=ma.end()){cnt++; ma[++val1]=false;}
                while(ma.find(val2-1)!=ma.end()){cnt++; ma[--val2]=false;}
                max_all = max(max_all, cnt);
                ma[it->first]=false;
            }
        }
        return max_all;
    }
};