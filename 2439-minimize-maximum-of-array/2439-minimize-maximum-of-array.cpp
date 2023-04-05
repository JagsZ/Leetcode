class Solution {
    bool isValid(int mid, vector<int> &nums){
        long sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > ((long)mid * (i+1)))
                return false;
        }
        return true;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int start = nums[0], end = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(start <= end){
            int mid = (start + end) / 2;
            if(isValid(mid, nums)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};