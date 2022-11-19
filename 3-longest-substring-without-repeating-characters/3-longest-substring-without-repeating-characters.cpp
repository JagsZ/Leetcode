class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, l = 0;
        set<char> string_set;
        
        for(int r = 0; r < s.length(); r++){
            if(string_set.find(s[r]) != string_set.end()){
                while(!string_set.empty() && string_set.find(s[r]) != string_set.end()){
                    string_set.erase(s[l]);
                    l++;
                }
            }
            string_set.insert(s[r]);
            max_len = max(max_len, (r-l)+1);
        }
        return max_len;
    }
};