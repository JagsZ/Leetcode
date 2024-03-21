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
        vector<vector<int>> memo(n, vector<int>(target+1, -1));
        if(sum % 2 != 0)
            return false;
        
        return solve(n-1, target, nums, memo);
    }
};