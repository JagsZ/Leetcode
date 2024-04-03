class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        int l = lower - nums.begin();
        int u = upper - nums.begin();
        if(l == n || nums[l] != target) return ans;
        ans[0] = l;
        ans[1] = u-1;
        return ans;
    }
};