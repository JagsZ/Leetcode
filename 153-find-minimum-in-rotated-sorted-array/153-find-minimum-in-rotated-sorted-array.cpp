class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0, end = nums.size()-1;
        int min_ele = INT_MAX;
        
        while(start <= end){   
            int mid = (start+end)/2;
            
            if(nums[start] <= nums[mid]){
                min_ele = min(min_ele, nums[start]);
                start = mid+1;
            }else{
                min_ele = min(min_ele, nums[mid]);
                end = mid-1;
            }
        }
        return min_ele;
    }
};