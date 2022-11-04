class Solution {
    bool isVovels(char ch){
        if(ch <= 90)
            ch += ' ';
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length()-1;
        string ans = s;
        
        while(l < r){
            if(isVovels(ans[l]) && isVovels(ans[r])){
                swap(ans[l], ans[r]);
                l++;
                r--;
            }
            else if(isVovels(ans[l])){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};