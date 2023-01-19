class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        int prefix_sum = 0, res = 0;
        
        for(auto num : nums){
            prefix_sum = (prefix_sum + (num) % k + k) % k;
            count[prefix_sum]++;
        }
        res = count[0];
        for(auto n : count){
            res += (n*(n-1))/2;
        }
        return res;
    }
};