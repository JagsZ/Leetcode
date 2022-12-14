class Solution {
    int solve(int indx, vector<int> &nums, vector<int> &memo){
        if(indx < 0)
            return 0;
        
        if(indx == 0)
            return nums[0];
        
        if(memo[indx] != -1)
            return memo[indx];
        
        int pick = nums[indx] + solve(indx-2, nums, memo);
        int not_pick = solve(indx-1, nums, memo);
        return memo[indx] = max(not_pick, pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(n-1, nums, memo);
    }
};