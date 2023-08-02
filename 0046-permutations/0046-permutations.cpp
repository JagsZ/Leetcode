class Solution {
    void permuteUtil(vector<int> &nums, int idx, vector<vector<int>> &list){
        if(idx == nums.size()-1){
            list.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            permuteUtil(nums, idx+1, list);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> out;
        permuteUtil(nums, 0, list);
        return list;
    }
};