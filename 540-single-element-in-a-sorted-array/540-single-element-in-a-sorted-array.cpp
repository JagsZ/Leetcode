class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        
        while(start < end-1){
        
            int mid = (start + end)/2;
            bool half_even = (end-mid) % 2 == 0; 
            if(nums[mid] == nums[mid+1]){
                if(half_even)
                    start = mid+2;
                else
                    end = mid-1;
            }else if(nums[mid-1] == nums[mid]){
                if(half_even)
                    end = mid-2;
                else
                    start = mid+1;
            }else{
                return nums[mid];
            }
        }
        return nums[start];
    }
};