class Solution {
    int solve(int indx, int prev_indx, vector<int> &nums, vector<vector<int>> &memo){
        if(indx < 0)
            return 0;
        
        if(memo[indx][prev_indx] != -1)
            return memo[indx][prev_indx];
        
        int not_pick = solve(indx-1, prev_indx, nums, memo);
        int pick = INT_MIN;
        if(prev_indx != indx+1)
            pick = nums[indx] + solve(indx-1, indx, nums, memo);
        return memo[indx][prev_indx] = max(not_pick, pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+2, vector<int>(n+2, -1));
        return solve(n-1, n+1, nums, memo);
    }
};