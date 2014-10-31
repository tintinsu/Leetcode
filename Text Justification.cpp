#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        if(L==0) {string s; ret.push_back(s); return ret;}
        
        int nWords=0, sum_len=0;
        for(int i=0;i<words.size();i++){
            if(nWords+sum_len <= L - words[i].size()){
                if(i+1 == words.size()){
                    // last row
                    string line;
                    for(int j=i-nWords;j<=i;j++){
                        line.append(words[j]);
                        if(j<i) line.append(1, ' ');
                    }
                    line.append(L-line.size(), ' ');
                    ret.push_back(line);
                }else{
                    // normal row
                    nWords++;
					sum_len+=words[i].size();
                }
            }else{
                // organize the last row
                string line;
                if(nWords == 1){
                    line.append(words[i-1]);
                    line.append(L-line.size(), ' ');
                }else{
                    int nSpace = (L-sum_len )/(nWords-1);
                    int rest = (L-sum_len )%(nWords-1);
                    for(int j=i-nWords;j<i-1;j++){
                        line.append(words[j]);
                        line.append(nSpace, ' ');
                        if(rest>0) {line.append(1, ' '); rest--;}
                    }
                    line.append(words[i-1]);
                }
                ret.push_back(line);
                
                // start with a new row
                nWords = 1;
				sum_len = words[i].size();
                if(i+1 == words.size()){
                    // last row
                    string line;
                    line.append(words[i]);
                    line.append(L-line.size(), ' ');
                    ret.push_back(line);
                }
            }
        }
        return ret;
    }
};

int main()
{
	Solution sol;
	const char *words[] = {"This", "is", "an", "example", "of", "text", "justification."};
	int nWords = sizeof(words)/sizeof(words[0]);
	vector<string> vec;
	for(int i=0;i<nWords;i++) vec.push_back(words[i]);
	vector<string> ret = sol.fullJustify(vec, 16);
	for(int i=0;i<ret.size();i++) cout<<ret[i]<<endl;
	system("pause");
	return 1;
}