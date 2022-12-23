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
        vector<vector<int>> memo(n, vector<int>(2,-1));
        return solve(0, 1, prices, memo);
    }
};