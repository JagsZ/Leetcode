class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), lis = 1, last = 0;
        vector<int> dp(n+1, 1);
        vector<int> hash(n+1, 0);
        vector<int> ans;
        
        for(int i = 1; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if((nums[i] % nums[prev]) == 0 && (1+dp[prev] > dp[i])){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                    lis = max(lis, dp[i]);
                }
            }
        }
        for(int i = 0; i <= n; i++){
            if(dp[i] == lis){
                last = i;
                break;
            }
        }  
        while( lis > 0){
            ans.push_back(nums[last]); 
            last = hash[last];
            lis --;
        }
        return ans;
    }
};