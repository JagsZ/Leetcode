class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, len = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                len++;
            }else{
                ans += (len * (len+1)) / 2; 
                len = 0;
            }
        }
        ans += (len * (len+1)) / 2;
        return ans;
    }
};