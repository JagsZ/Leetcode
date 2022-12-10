class Solution {
    int atMost(vector<int> &nums, int k){
        int n = nums.size(), p1= 0, p2 = 0, count = 0;
        unordered_map<int, int> freq;
        
        while(p1 < n){
            freq[nums[p1]]++;
            while(freq.size() > k){
                freq[nums[p2]]--;
                if(freq[nums[p2]] == 0)
                    freq.erase(nums[p2]);
                p2++;
            }
            count += (p1-p2+1);
            p1++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atMost(nums, k) - atMost(nums, k-1));
    }
};