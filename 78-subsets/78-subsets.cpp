class Solution {
    void solve(int index, int n, vector<int> &nums, vector<int> &out, vector<vector<int>> &list){
        if(index == n){
            list.push_back(out);
            return;
        }
        out.push_back(nums[index]);
        solve(index+1, n, nums, out, list);
        out.pop_back();
        solve(index+1, n, nums, out, list);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> out;
        int n = nums.size();
        solve(0, n, nums, out, list);
        return list;
    }
};