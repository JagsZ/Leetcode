class Solution {
    int solve(int indx, int target, vector<int> &nums, vector<vector<int>> &memo){
        if(indx == 0){
            if(target % nums[indx] == 0)
                return(target/nums[indx]);
            return 1e9;
        }
        if(memo[indx][target] != -1)
            return memo[indx][target];
        
        int not_take = solve(indx-1, target, nums, memo);
        int take = 1e9;
        if(nums[indx] <= target)
            take = 1 + solve(indx, target- nums[indx], nums, memo);
        return memo[indx][target] = min(not_take, take);
    }
public:
    int numSquares(int n) {
        vector<int> sqr_num;
        
        for(int i = 1; i <= n; i++){
            if(ceil((double)sqrt(i)) == (floor((double)sqrt(i)))){
                sqr_num.push_back(i);
            }
        }
        int sqr_size = sqr_num.size();
        vector<vector<int>> memo(sqr_size+1, vector<int>(n+1, -1));
        int ans = solve(sqr_num.size()-1, n, sqr_num, memo);
        return ans == 1e9? -1 : ans;
    }
};