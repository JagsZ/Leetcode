class Solution {
    int func(int i,int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp)
    {
        if(i==nums1.size()||j==nums2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int count=0;
        if(nums1[i]==nums2[j])
        {
            count=1+func(i+1,j+1,nums1,nums2,dp);
        }
        else
        {
            count+=max(func(i+1,j,nums1,nums2,dp),func(i,j+1,nums1,nums2,dp));
        }
        return dp[i][j]=count;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return func(0,0,nums1,nums2,dp);
    }
};