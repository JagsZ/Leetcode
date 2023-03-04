class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mi_pos = -1, mx_pos = -1, left_pos = -1;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] < minK || nums[i] > maxK)
                    left_pos = i;
            
                if(nums[i] == minK)
                    mi_pos = i;
                if(nums[i] == maxK)
                    mx_pos = i;
                
                ans += max(0, min(mi_pos, mx_pos) - left_pos);
        }
        return ans;
    }
};