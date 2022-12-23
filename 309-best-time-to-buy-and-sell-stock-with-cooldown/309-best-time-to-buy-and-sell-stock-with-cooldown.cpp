class Solution {
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &memo){
       int profit = 0;
       if(index >= prices.size())
           return 0;
        
       if(memo[index][buy] != -1)
           return memo[index][buy];
        
       if(buy){
           profit = max((-prices[index] + solve(index+1, 0, prices, memo)), (0 + solve(index+1, 1, prices, memo)));
       }else{
            profit = max((prices[index] + solve(index+2, 1, prices, memo)), (0 + solve(index+1, 0, prices, memo)));
       }
       return memo[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        
        for(int index = n-1; index >=0; index--){
            
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                }else{
                    profit = max(prices[index] + dp[index+2][1], dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};