class Solution {
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int prev1 = nums[0], prev2 = 0;
        
        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            int not_pick = prev1;
            int curr = max(pick, not_pick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};