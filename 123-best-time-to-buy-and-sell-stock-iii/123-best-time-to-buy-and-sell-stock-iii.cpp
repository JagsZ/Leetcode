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
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, memo);   
    }
};