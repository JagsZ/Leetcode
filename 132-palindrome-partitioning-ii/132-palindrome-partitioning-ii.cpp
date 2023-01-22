class Solution {
     bool isPalindrome(string &s, int l, int r){
        while(l <= r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1 , 0);
        vector<vector<int>> palindrome_table(n, vector<int>(n, -1));
        
        for(int index = n-1; index >= 0; index--){
            int min_cost = INT_MAX;
            for(int i = index; i < n; i++){
                if(palindrome_table[index][i] != -1 ? palindrome_table[index][i]: palindrome_table[index][i] = isPalindrome(s, index, i)){
                    int cost = 1 + dp[i+1];
                    min_cost = min(min_cost, cost);
                }
            }
            dp[index] = min_cost;
        }
        return dp[0] - 1;
    }
};