class Solution {
   
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hs(26, 0);
        vector<int> hp(26, 0);
        
        int l = 0, r = p.length()-1;
        vector<int> ans;
        
        for(auto ch : p)
            hp[ch - 'a']++;
        
        for(int i = l; i < r && i < s.length(); i++){
            hs[s[i] - 'a']++;
        }
        
        while(r < s.length()){
            hs[s[r] - 'a']++;
            if(hs == hp)
                ans.push_back(l);
            hs[s[l] - 'a']--;
            l++;
            r++;
        }
        return ans;
    }
};