class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), curr_sum = 0;
        unordered_map<int, int> map;
        
        for(int i  = 0; i < n; i++){
            if(nums[i] % 2 == 0)
                nums[i] =  0;
            else
                nums[i] = 1;
        }
        for(int i = 0; i < n; i++){
            curr_sum += nums[i];
            if(curr_sum == k)
                count++;
            if(map.find(curr_sum - k) != map.end()){
                count += map[curr_sum - k];
            }
            map[curr_sum]++;
        }
        return count;
    }
};