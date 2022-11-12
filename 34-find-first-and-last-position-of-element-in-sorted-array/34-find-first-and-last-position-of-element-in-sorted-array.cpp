class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int index1 = -1, index2 = -1;
        if(nums.size() == 0)
            return ans;
        index1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(index1 < nums.size() && nums[index1] == target){
            index2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(index2 == nums.size()){
                index2--;
            }
            if(nums[index2] != target){
                index2--;
            }
            ans[0] = index1;
            ans[1] = index2;
        }
        return ans;
    }
};