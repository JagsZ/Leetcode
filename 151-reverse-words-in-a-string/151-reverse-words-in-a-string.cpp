class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        
        for(int i = 0; i < s.length(); i++){
            string word = "";
            if(s[i] != ' '){
                if(ans != "")
                    ans = ' ' + ans;
                while(i < s.length() && s[i] != ' '){
                    word += s[i];
                    i++;
                }
                ans = word + ans;
            }
        }
        return ans;
    }
};