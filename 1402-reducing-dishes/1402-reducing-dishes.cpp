class Solution {
    int solve(int index, int time, vector<int> &nums, vector<vector<int>> &memo){
        if(index == nums.size())
            return 0;
        
        if(memo[index][time] != -1)
            return memo[index][time];
        
        int not_take = 0 + solve(index+1, time, nums, memo);
        int take = (nums[index] * time) + solve(index+1, time+1, nums, memo);
        return memo[index][time] = max(take, not_take);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(0, 1, satisfaction, memo);
    }
};