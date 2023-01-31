class Solution {
    int solve(int index, int prev, vector<pair<int, int>> &nums,                         vector<vector<int>> &memo){
        
        if(index >= nums.size())
            return 0;
        
        if(memo[prev+1][index] != -1)
            return memo[prev+1][index];
        
        int not_take = 0 + solve(index+1, prev, nums, memo);
        int take = 0;
        if(prev == -1 || nums[index].second >= nums[prev].second){
            take = nums[index].second + solve(index+1, index, nums, memo); 
        }
        return memo[prev+1][index] = max(take, not_take);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> nums;
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        
        for(int i = 0; i < n; i++){
            nums.push_back({ages[i], scores[i]});
        }
        sort(nums.begin(), nums.end());
        return solve(0, -1, nums, memo);
    }
};