class Solution {
public:
    string simplifyPath(string path) {
        // push words into a stack
        string word;
        stack<string>sta;
        path.append(1,'/');
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(word.empty()) continue;
                if(word.compare("..")==0){
                    if(!sta.empty()) sta.pop();
                }else if(word.compare(".")!=0){
                    sta.push(word);
                }
                word.clear();
            }else{
                word.append(1,path[i]);
            }
        }
        
        // analyze the stack
        string ret;
        if(sta.empty()) return "/";
        while(!sta.empty()){
            ret.insert(0, sta.top());
            sta.pop();
            ret.insert(0,1,'/');
        }
        // return the answer
        return ret;
    }
};