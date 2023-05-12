class Solution {
    long long solve(int index, vector<vector<int>> &nums, vector<long long> &memo){
        if(index >= nums.size())
            return 0;
        
        if(memo[index] != -1)
            return memo[index];
        
        long long take = nums[index][0] + solve(index+nums[index][1]+1, nums, memo);
        long long not_take = solve(index+1, nums, memo);
        return memo[index] = max(take, not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> memo(n, -1);
        return solve(0, questions, memo);
    }
};