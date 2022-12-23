class Solution {
  
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(5, 0);
        vector<int> curr(5, 0);
        
        for(int index = n-1; index >= 0; index--){
            for(int tr = 3; tr >= 0; tr--){
                    int profit = 0;
                    if(tr % 2 == 0){
                        profit = max(-prices[index] + prev[tr+1], prev[tr]);
                    }else{
                        profit = max(prices[index] + prev[tr+1], prev[tr]);
                    }
                    curr[tr] = profit;
                }
                prev = curr;
        }
        return prev[0];
    }
};