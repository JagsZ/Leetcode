class Solution {
    bool solve(int index, int n, vector<int> & nums, vector<int> &memo){
        if(index == nums.size()-1)
            return true;
        
        if(index >= nums.size())
            return false;
        
        if(memo[index] != -1)
            return memo[index];
        
        for(int i = 1; i <= nums[index]; i++){
            if(i+index < nums.size()){
                if(solve(i+index, n, nums, memo) == true)
                    return memo[i+index] = true;
            }
        }
        return memo[index] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(0, n,  nums, memo);
    }
};