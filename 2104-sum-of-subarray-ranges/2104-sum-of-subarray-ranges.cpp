class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int min_val = nums[i], max_val = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                min_val = min(min_val, nums[j]);
                max_val = max(max_val, nums[j]);  
                ans += (max_val - min_val); 
            } 
        }
        return ans;
    }
};