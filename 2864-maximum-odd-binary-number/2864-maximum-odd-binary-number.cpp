class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int r = s.length()-1, index = 0;
        for(int i = r; i >= 0; i--){
            if(s[i] == '1'){
                swap(s[r], s[i]);
                break;
            }
        }
        for(int i = 0; i < r; i++){
            if(s[i] == '1'){
                swap(s[index], s[i]);
                index++;
            }
        }
        return s;
    }
};