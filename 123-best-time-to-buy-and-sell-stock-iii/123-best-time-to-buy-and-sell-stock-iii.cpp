class Solution {
  
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index] + prev[0][cap], prev[1][cap]);
                    }else{
                        profit = max(prices[index] + prev[1][cap-1], prev[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            prev = curr;
        }
        return prev[1][2];
    }
};