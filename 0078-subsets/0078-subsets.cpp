class Solution {
    public:
    void solve(int indx, vector<int>&nums, vector<int> &out, vector<vector<int>> &list){
        
        if(indx == nums.size()){
            list.push_back(out);
            return;
        }
        
        out.push_back(nums[indx]);
        solve(indx+1, nums, out, list);
        out.pop_back();
        solve(indx+1, nums, out, list);
    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> out;
        solve(0, nums, out, list);
        return list;
    }
};