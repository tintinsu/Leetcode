class Solution {
public:
    string intToRoman(int num) {
        // intiailization
        int idx=0;
        char roman[]="IVXLCDM";
        string ret;
        
        // loop
        while(num>0){
            int d = num%10;
            switch(d){
                case 1:
                case 2:
                case 3:
                    ret.insert(0,d,roman[idx]);
                    break;
                case 4:
                case 5:
                    ret.insert(0,1,roman[idx+1]);
                    ret.insert(0,5-d,roman[idx]);
                    break;
                case 6:
                case 7:
                case 8:
                    ret.insert(0,d-5,roman[idx]);
                    ret.insert(0,1,roman[idx+1]);
                    break;
                case 9:
                    ret.insert(0,1,roman[idx+2]);
                    ret.insert(0,1,roman[idx]);
                    break;
            }
            
            // update
            idx += 2;
            num /= 10;
        }
        
        // return
        return ret;
    }
};