class Solution {
public:
    string removeStars(string s) {
        int index = s.length()-1, count = 0;
        string ans = "";
        while(index >= 0){
            if(s[index] != '*' && count == 0){
                ans.push_back(s[index]);
            }else{
                if(s[index] == '*'){
                   count++; 
                }else{
                    count--;
                }
            }
            index--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};