class Solution {
 int helperOPDP(string &src, int start, int end, vector<vector<int>> &dp){
    if(start > end){
        return 0;
    }
    if(start == end){
        return 1;
    }
    if(dp[start][end] == -1){
        if(src[start] == src[end]){
            dp[start][end] = (2+helperOPDP(src, start+1,end-1,dp));
        }else{
            dp[start][end] = max(helperOPDP(src, start, end-1,dp), helperOPDP(src, start+1, end,dp));
        }
    }
    return dp[start][end];
}
public:
    int longestPalindromeSubseq(string s) {
       int n=s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helperOPDP(s, 0,s.length()-1, dp);         
    }
};