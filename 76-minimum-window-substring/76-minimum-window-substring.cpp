class Solution {

public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;

        int ns = s.length(), nt = t.length();

        for(int i=0;i<nt;i++) {
            mt[t[i]]++;
        }
        int l = 0;
        const int inf = 1e9;
        int si, len=inf;
        int matched = 0;
        for(int i=0;i<ns;i++) {
            ms[s[i]]++;
            if(mt.count(s[i]) && ms[s[i]] <= mt[s[i]]) {
                matched++;
            }
            while(matched == nt) {
                if(i-l + 1 < len) {
                    si = l; len = i - l + 1;
                }                
                if(mt.count(s[l]) && ms[s[l]] <= mt[s[l]]) {
                    matched--;
                }
                ms[s[l]]--; 
                l++;
            }
        }
        if(len == inf) return "";
        return s.substr(si, len);
    }
};