class Solution {
    int solve(int index1, int index2, string &word1, string &word2, vector<vector<int>> &memo){
        if(index1 < 0)
            return index2+1;
        if(index2 < 0)
            return index1+1;
        
        if(memo[index1][index2] != -1)
            return memo[index1][index2];
        
        int match = 0, not_match = 0;
        if(word1[index1] == word2[index2])
            match = solve(index1-1, index2-1, word1, word2, memo);
        else
            not_match = 1 + min(solve(index1-1, index2-1, word1,word2, memo), min(solve(index1-1, index2, word1, word2,memo), solve(index1, index2-1, word1, word2,memo)));
        return memo[index1][index2] = (match+not_match);
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1, word1, word2, memo);
    }
};