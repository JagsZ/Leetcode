class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size()-1, max_price = 0, max_profit = 0;;
        
        for(int i = n; i >= 0; i--){
            max_price = max(max_price, prices[i]);
            int curr_profit = max_price - prices[i];
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};