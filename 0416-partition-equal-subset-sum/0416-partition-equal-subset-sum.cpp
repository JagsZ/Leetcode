class Solution {
    bool solve(int i, int target, vector<int>&nums, vector<vector<int>> &memo){
        if(target == 0)
            return true;
        
        if(i == 0){
            if(target == nums[0])
                return true;
            return false;
        }
        
        if(memo[i][target] != -1)
            return memo[i][target];
        
        int not_take = solve(i-1, target, nums, memo);
        int take = false;
        if(nums[i] <= target)
            take = solve(i-1, target-nums[i], nums, memo);
        return memo[i][target] = (take | not_take);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, target = 0, n = nums.size();
        
        for(auto x : nums)
            sum += x;
        target = sum/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        if(sum % 2 != 0)
            return false;
        
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= target; j++){
                int not_take = dp[i-1][j];
                int take = false;
                if(nums[i] <= j)
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = (take | not_take);
            }
        }
        return dp[n-1][target];
    }
};