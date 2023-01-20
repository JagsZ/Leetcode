class Solution {
    void solve(int index, vector<int> &nums, vector<int> &seq, set<vector<int>> &list){
        
        if(index == nums.size()){
            if(seq.size() >= 2)
                list.insert(seq);
            return;
        }
        
        if(seq.size() == 0 || seq.back() <= nums[index]){
            seq.push_back(nums[index]);
            solve(index+1, nums, seq, list);
            seq.pop_back();
        }
        solve(index+1, nums, seq, list);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> list;
        vector<int> seq;
        
        solve(0, nums, seq, list);
        return vector(list.begin(), list.end());
    }
};