class Solution {
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &memo){
        if(i > j)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int min_cost = INT_MAX;
        for(int index = i; index <= j; index++){
            int cost = cuts[j+1] - cuts[i-1] + solve(index+1, j, cuts, memo) +
                    solve(i, index-1, cuts, memo);
            min_cost = min(min_cost, cost);
        }
        return memo[i][j] = min_cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int len = cuts.size();
        vector<vector<int>> memo(len+1, vector<int>(len+1, -1));
        
        sort(cuts.begin(), cuts.end());
        return solve(1, len-2, cuts, memo);
    }
};