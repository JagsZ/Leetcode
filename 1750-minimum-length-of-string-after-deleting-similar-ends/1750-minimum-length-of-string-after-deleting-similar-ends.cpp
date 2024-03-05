class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
                while(l < r && s[l] == s[l-1]){
                    l++;
                }
                while(r > l && s[r] == s[r+1]){
                    r--;
                }
            }else{
                break;
            }   
        }
        if(l > 0 && s[l] == s[l-1])
            return 0;
        return (r-l+1);
    }
};