int mod = 1e9 + 7;
int p = 31;
class Solution {
public:
   int strStr(string haystack, string needle) {
        int ans = -1, n = haystack.size(), m = needle.size();
        
        // If size of second string is greater than first string
        if(n < m) {
            return ans;
        }
        
        for(int i=0; i<=n-m; i++) {
            bool flag = true;
            // Searching needle in haystack 
            for(int j=i, k=0; k<m; j++,k++) {
                if(haystack[j] != needle[k]) {
                    flag = false;
                    break;
                }
            }
            // If needle found
            if(flag) {
                return i;
            }
        }
        return ans;
    }
};