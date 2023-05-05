class Solution {
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || 
                  ch == 'o' || ch == 'u')
            return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int l = 0, ans = 0, count = 0;
        for(int i = 0; i < s.length(); i++){
            if(i - l + 1 <=  k){
                if(isVowel(s[i])){
                    count++;
                }
            }else{
                if(isVowel(s[i]) && !isVowel(s[l])){
                    count++;
                }else if(!isVowel(s[i]) && isVowel(s[l])){
                    count--;
                }
                l++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};