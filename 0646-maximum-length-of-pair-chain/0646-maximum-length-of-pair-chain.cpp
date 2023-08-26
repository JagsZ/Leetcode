class Solution {
    int solve(int index, int prev, vector<vector<int>>& pairs, 
              vector<vector<int>> &memo){
        if(index == pairs.size())
            return 0;
        
         if(memo[index][prev+1] != -1)
            return memo[index][prev+1];
        
        int not_pick = solve(index+1, prev, pairs, memo);
        int pick = 0;
        if(prev == -1 || (pairs[index][0] > pairs[prev][0] && pairs[prev][1] < pairs[index][0]))
            pick = 1 + solve(index+1, index, pairs, memo);
        return memo[index][prev+1] = max(pick, not_pick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {  
        int n = pairs.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs, memo);
    }
};