class Solution {
    int solve(int indx1, int indx2, string &s1, string &s2, vector<vector<int>> &memo){
        if(indx1 == 0 || indx2 == 0){
            return 0;
        }
        if(memo[indx1][indx2] != -1){
            return memo[indx1][indx2];
        }
        if(s1[indx1-1] == s2[indx2-1]){
            return memo[indx1][indx2] = 1 + solve(indx1-1, indx2-1, s1,s2, memo);
        }
        return memo[indx1][indx2] = max(solve(indx1-1, indx2,s1,s2, memo), 
                                        solve(indx1, indx2-1, s1,s2, memo));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        /*
        vector<vector<int>> memo(n1+1, vector<int>(n2+1, 0));
        return solve(n1, n2, text1, text2, memo);
        
        */
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int index1 = 1; index1 <= n1; index1++){
            for(int index2 = 1; index2 <= n2; index2++){
                if(text1[index1-1] == text2[index2-1]){
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];
                }else{
                    dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};