class Solution {
public:
    bool search(vector<int>& nums, int target) {
    
        int start = 0, end = nums.size()-1;
        
        while(start < end){
            int mid = ((start+end)/2);
            if(target == nums[mid])
                return true;
            // if not able to identify which half is sorted.
            // in this case target is not mid so we can shrinck the array
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
            }
            else if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }else{
                if(target > nums[mid] && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return nums[start] == target? true : false;
    }
};