class Solution {
    int binarySearch(long long target, vector<int> &nums){
        int start = 0, end = nums.size()-1;
        
        while(start < end){
            int mid = (start + end) / 2;
            if(target <= nums[mid]){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        if(start < nums.size() && nums[start] < target)
                start++;
        return nums.size() - start;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        
        for(int i = 0; i < spells.size(); i++){
            if(spells[i] != 0){
                long long target = ceil(1.0 * success / spells[i]);
                int count = binarySearch(target, potions);
                ans.push_back(count);
            }
        }
        return ans;
    }
};