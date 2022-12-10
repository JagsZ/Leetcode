class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int p1 = 0, p2 = 0, n = s.length(), count = 0;
        unordered_map<char, int> freq;
        int len = 0 ;
        if(k <= 0)
            return count;
        while(p1 < n){
            if(freq.size() < k){
                freq[s[p1]]++;
            }else{
                freq[s[p1]]++;
                while( p2 <= p1 && freq.size() > k){
                    if(freq[s[p2]] > 1){
                        freq[s[p2]]--;
                    }else{
                        freq.erase(s[p2]);
                    }
                    p2++;
                }
                //count = max(count, (p1-p2+1));
            }
            count = max(count, (p1-p2+1));
            p1++;
        }
        count = max(count, (p1-p2));
        return count;
    }
};