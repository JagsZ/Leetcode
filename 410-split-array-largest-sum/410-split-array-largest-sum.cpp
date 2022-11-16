class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l =  *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        
        while(l < r){
            int mid = (l+r)/2;
            int t_day = 0, sum = 0;
            
            for(int i = 0; i < n; i++){
                sum += nums[i];
                if(sum > mid){
                    t_day++;
                    sum = nums[i];
                }
                else if(sum == mid){
                    t_day++;
                    sum = 0;
                }
            }
            if(sum)
                t_day++;
            if(t_day > k){
                l = mid+1;
            }else{
                 r = mid;
            }
        }
        return r;
    }
};