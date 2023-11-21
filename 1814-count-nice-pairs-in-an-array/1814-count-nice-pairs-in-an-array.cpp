class Solution {
public:
    int rev(int i){
        int rnum = 0;
        while(i>0){
            int digit = i%10;
            rnum = rnum*10 + digit;
            i/=10;
        }
        return rnum;
    }

    int countNicePairs(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]-rev(nums[i])]++;
        }

        int m = 1e9+7;
        long long int ans = 0;
        for(auto it: mp){
            long long val = it.second;
            long long cnt = (val*(val-1))/2;
            ans+=cnt;
            ans%=m;
        }
        return ans;
        
    }
};