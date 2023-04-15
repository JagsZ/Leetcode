class Solution {
public:
    int solve(vector<vector<int>> &piles, vector<vector<int>> &dp, int k, int currPile)
{
    if (k == 0 || currPile >= piles.size()) return 0;

    if (dp[currPile][k] != -1) return dp[currPile][k];

    int size = piles[currPile].size();
    int coinsToTake = min(k, size);

    int currMax = solve(piles, dp, k, currPile + 1);

    for (int i = 0; i < coinsToTake; i++)
    {
        currMax = max(currMax, piles[currPile][i] + solve(piles, dp, k - (i + 1), currPile + 1));
    }

    return dp[currPile][k] = currMax;
}

int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
    for(int i = 0 ; i < piles.size(); i++)
        for(int j = 1 ; j < piles[i].size(); j++)
            piles[i][j] = piles[i][j] + piles[i][j-1];

    vector<vector<int>> dp(piles.size()+1,vector<int> (k+1,-1));

    return solve(piles,dp,k,0);
}
};