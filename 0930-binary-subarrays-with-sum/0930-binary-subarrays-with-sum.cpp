class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, curr = 0, ans=0; 
        unordered_map<int, int> map;
        map[0] = 1;
        for(int  r = 0; r < nums.size(); r++){
            curr += nums[r];
            if(map.count(curr-goal)){
                ans += map[curr-goal];
            }
            map[curr]++;
            
        }
        return ans;
    }
};