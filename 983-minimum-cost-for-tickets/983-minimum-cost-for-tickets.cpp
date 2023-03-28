class Solution {
public:
       int f(vector<int>&d,vector<int>&c,int ind,int pre,vector<vector<int>>&dp){
        if(ind==d.size()) return 0;
        if(pre>=d[ind])
            return f(d,c,ind+1,pre,dp);
        if(dp[ind][pre]!=-1) return dp[ind][pre];
        int x=1e9,y=1e9,z=1e9;
        x=f(d,c,ind+1,0,dp)+c[0];
        y=f(d,c,ind+1,d[ind]+7-1,dp)+c[1];
        z=f(d,c,ind+1,d[ind]+30-1,dp)+c[2];
        return dp[ind][pre]=min({x,y,z});
    }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        vector<vector<int>>dp(d.size(),vector<int>(366,-1));
        return f(d,c,0,0,dp);
    }
};