class Solution {
    void helper(vector<int> &cost, int index, int out, int &ans){
        if(index >= cost.size()-1){
            ans = min(ans, out);
            return;
        }
        for(int i=0; i<=1; i++){
            helper(cost, index+1+i, out+cost[i+index], ans);
        }
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ans=INT_MAX;
        int n = cost.size();
        vector<int> dp(n+1, 0);
        //helper(cost, 0, 0, ans, dp);
        
        for(int i=2; i<n+1; i++){
            int take = dp[i-1] + cost[i-1];
            int not_take = dp[i-2] + cost[i-2];
            dp[i] = min(take, not_take);
        }
        return dp[n];
    }
};