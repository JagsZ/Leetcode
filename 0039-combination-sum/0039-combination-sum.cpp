class Solution {
    void combination(int indx, int target, vector<int>& nums, 
                     vector<int>& out, vector<vector<int>>& list){
        if(indx == nums.size()){
            if(target == 0){
                list.push_back(out);
            }
            return;
        }
        
        if(target >= nums[indx]){
            out.push_back(nums[indx]);
            combination(indx, target-nums[indx], nums, out, list);
            out.pop_back();
        }
        combination(indx+1, target, nums, out, list);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> list;
        combination(0, target, candidates, out, list);
        return list;
    }
};