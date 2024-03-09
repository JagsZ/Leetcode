class Solution {
    bool binary_search(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        while( l <= r){
            int mid = (l+r)/2;
            if(target == nums[mid])
                return true;
            else if( target < nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
    
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            if(binary_search(nums2, nums1[i]))
                ans = min(ans, nums1[i]);
        }
        return ans == INT_MAX? -1 : ans;
    }
};