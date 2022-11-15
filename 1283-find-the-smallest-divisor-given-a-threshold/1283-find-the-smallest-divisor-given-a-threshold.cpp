class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = *max_element(nums.begin(), nums.end());
        
        while(l < r){
            int mid = (l+r)/2;
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (nums[i] / mid) + (nums[i] % mid != 0);
            }
            if(sum <= threshold){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};