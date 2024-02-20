class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i && nums[i] != nums.size())
                swap(nums[i], nums[nums[i]]);
            else
                i++;
        }
        for(i = 0; i < nums.size(); i++){
            if(i != nums[i])
                return i;
        }
        return i;
    }

};