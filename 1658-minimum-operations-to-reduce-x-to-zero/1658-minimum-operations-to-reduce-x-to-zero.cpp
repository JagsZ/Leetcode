class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> map;
        int ans=0,sum=0, target_sum=0;
        
        for(auto x : nums)
            sum += x;
        
        target_sum = sum -x;
        int prefix=0;
        int maxlen=-1;
        map[0] = -1;
        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            map[prefix] = i;
            if(map.find(prefix-target_sum) != map.end()){
                int len = i - map[prefix-target_sum];
                maxlen = max(len, maxlen);
            }
            
        }
        if(maxlen == -1)
            return maxlen;
        else
            return nums.size()-maxlen;
    }

};