class Solution {
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &memo){
        
        if(i < 0 || j < 0)
            return 0;
        
         if(i == 0 && j == 0)
            return 1;
        
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int left = solve(i, j-1, obstacleGrid, memo);
        int right = solve(i-1, j, obstacleGrid, memo);
        return memo[i][j] = (left+right);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        if(obstacleGrid[0][0])
            return 0;
        return solve(m-1, n-1, obstacleGrid, memo);
    }
};