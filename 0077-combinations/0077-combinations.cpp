class Solution {
public:
    void solve(int index, int end, int k, vector<vector<int>>&ans, vector<int>&ds)
    {
        if(k==0) 
        {
            ans.push_back(ds);
            return;
        }
        if(index>end) return;
        ds.push_back(index);
        solve(index+1,end,k-1,ans,ds);
        ds.pop_back();
        solve(index+1,end,k,ans,ds);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,n,k,ans,ds);
        return ans;
    }
};