class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int tr_size = 2*k;
        vector<int> prev(tr_size+1, 0);
        vector<int> curr(tr_size+1, 0);
        
        for(int index = n-1; index >= 0; index--){
            for(int tr = tr_size-1; tr >= 0; tr--){
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