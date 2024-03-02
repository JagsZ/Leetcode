class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums[r] < 0)
            reverse(nums.begin(), nums.end());
        while(l <= r){
            if(abs(nums[l]) > abs(nums[r])){
                swap(nums[l], nums[r]);
                nums[r] = nums[r]*nums[r];
            }
            else{
                nums[r] = nums[r]*nums[r];
            }
            r--;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};