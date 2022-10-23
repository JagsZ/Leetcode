class Solution {
    void cyclicSort(vector<int> &nums){
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++){
            while(i != nums[i]-1){
                int index = nums[i]-1;
                if(index+1 == nums[index])
                    break;
                swap(nums[index], nums[i]);
            }
        }
    }
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        
        cyclicSort(nums);
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};