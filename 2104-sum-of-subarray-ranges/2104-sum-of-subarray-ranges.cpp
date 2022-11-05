class Solution {
private:
    int minMaxDiff(vector<int> &nums, int start, int end){
        int min_val = INT_MAX, max_val = INT_MIN;
        while(start <= end){
            min_val = min(min_val, nums[start]);
            max_val = max(max_val, nums[start]);
            start++;
        }
        return abs(min_val-max_val);
    }
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