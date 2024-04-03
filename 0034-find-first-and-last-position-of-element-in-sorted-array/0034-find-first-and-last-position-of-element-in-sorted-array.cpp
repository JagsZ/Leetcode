class Solution {
    int my_lower_bound(vector<int> &nums, int target){
        int n = nums.size();
        int l = 0, h = n-1, first = n;
        while(l <= h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
                first = mid;
                h = mid-1;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return first;
    }
    
     int my_upper_bound(vector<int> &nums, int target){
        int n = nums.size();
        int l = 0, h = n-1, last = n;
        while(l <= h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
               last = mid;
               l = mid+1;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return last+1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        int l  = my_lower_bound(nums, target);
        int u = my_upper_bound(nums, target);
  
        if(l == n || nums[l] != target) return ans;
        ans[0] = l;
        ans[1] = u-1;
        return ans;
    }
};