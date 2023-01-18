class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, max_sum = nums[0], n = nums.size(), min_sum = nums[0], curr_max = 0, curr_min = 0;
        
        for(int i = 0; i < n; i++){
            curr_max = max(curr_max, 0) + nums[i];
            max_sum = max(max_sum, curr_max);
            curr_min = min(curr_min, 0) + nums[i];
            min_sum = min(min_sum, curr_min);
            sum += nums[i];
        }
        return sum == min_sum? max_sum : max(max_sum, (sum - min_sum));
    }
};