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
    int solve(int index, int n, string s, vector<int> &memo){
        if(index == n)
            return 0;
        
        if(memo[index] != -1){
            return memo[index];
        }
        
        int min_cost = INT_MAX;
        for(int i = index; i < n; i++){
            if(isPalindrome(s, index, i)){
                int cost = 1 + solve(i+1, n, s, memo);
                min_cost = min(min_cost, cost);
            }
        }
        return memo[index] = min_cost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> memo(n , -1);
        return solve(0, n, s, memo) - 1;
    }
};