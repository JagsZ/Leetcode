class Solution {
    bool solve(int index, int n, string s, vector<string> dict, unordered_set<string> &set, 
               vector<int> &memo){
        
        if(index == n)
            return true;
        
        if(memo[index] != -1)
            return memo[index];
        
        bool status = false;
        for(int i = 0; i < dict.size(); i++){
            string word = dict[i];
            string substr = s.substr(index, word.length());
            if(index + word.length() <= n && set.find(substr) != set.end()){
                status |= solve(index+word.length(), n, s, dict, set, memo);
            }
        }
        return memo[index] = status;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<int> memo(s.length(), -1);
        for(auto st : wordDict)
            set.insert(st);
        
        return solve(0, s.length(), s, wordDict, set, memo);
    }
};