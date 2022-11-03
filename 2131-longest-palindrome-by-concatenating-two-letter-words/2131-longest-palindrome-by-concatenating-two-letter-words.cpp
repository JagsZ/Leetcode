typedef pair<string, int> pi; 
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        bool central = false;
        unordered_map<string, int> freq;
        
        for(int i = 0; i < words.size(); i++)
            freq[words[i]]++;
        
        for(auto x : freq){
            if(x.first[0] == x.first[1]){
                if(x.second % 2 == 0)
                    ans += 2*x.second;
                else{
                    ans += 2 *(x.second - 1);
                    central = true;
                    }
            }else{
                string str = x.first;
                reverse(str.begin(), str.end());
                if(freq.find(str) != freq.end()){
                    ans += 2 * (2 * min(freq[str], x.second));
                    freq[x.first] = 0;
                }
            }
        }
        if(central)
            ans += 2;
        return ans;
    }
};