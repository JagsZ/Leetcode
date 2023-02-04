class Solution {
    bool isPermutation(int l, int r, string &s2, unordered_map<char, int> s1_hash){
        while(l <= r){
            if(s1_hash.find(s2[l]) == s1_hash.end() || s1_hash[s2[l]] <= 0){
                return false;
            }
            s1_hash[s2[l]]--;
            l++;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_hash;
        int len = s1.length(), l = 0, r = s1.length()-1;
        
        if(len > s2.length())
            return false;
        
        for(auto ch : s1)
            s1_hash[ch]++;
        
        while(r < s2.length()){
            if(isPermutation(l, r, s2, s1_hash))
                return true;
            l++;
            r++;
        }
        return false;
    }
};