class Solution {
    void cyclicSort(vector<int> &nums){
    int index=0;
    for(int i=0; i<nums.size();i++){
        while(nums[i] != i+1 && nums[i] > 0 && nums[i] <= nums.size()){
            index = nums[i] - 1;
            if(nums[index] == index+1)
                break;
            swap(nums[i], nums[index]);
        }
    }    
}
    
public:
    int firstMissingPositive(vector<int>& nums) {
    int out=0;
    int i=0;
    cyclicSort(nums);
   
    for(i=0; i<nums.size(); i++){
        if(nums[i] != i+1){
            out = i+1;
            break;
        }
    }
    if(out==0)
        out = nums[i-1]+1;
    return out;
    }
};