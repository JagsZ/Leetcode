class Solution {
    int solve(int index, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &memo){
        int profit = 0;
        if(index == prices.size())
            return 0;
        
        if(cap == 0)
            return 0;
        
        if(memo[index][buy][cap] != -1)
            return memo[index][buy][cap];
        
        if(buy){
            profit = max((-prices[index] + solve(index+1, 0, cap, prices, memo)), (0 + solve(index+1, 1, cap, prices, memo)));
        }else{
            profit = max((prices[index] + solve(index+1, 1, cap-1, prices, memo)), (0 + solve(index+1, 0, cap, prices, memo)));
        }
        return memo[index][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index] + dp[index+1][0][cap], dp[index+1][1][cap]);
                    }else{
                        profit = max(prices[index] + dp[index+1][1][cap-1], dp[index+1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};