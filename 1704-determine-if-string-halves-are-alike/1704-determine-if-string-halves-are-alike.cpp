class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int len = s.length();
        for(int i = 0; i < (len/2); i++){
            char ch = s[i];
            if(s[i] < 'a')
                ch = s[i] + ' ';
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count++;
            }
        }
        for(int i = (len/2); i < len; i++){
            char ch = s[i];
            if(s[i] < 'a')
                ch = s[i] + ' ';
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count--;
            }
        }
        return count == 0 ? true : false;
    }
};