class Solution {
    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &memo){
        if(row == 0 && col == 0)
            return grid[row][col];
        if(row < 0 || col < 0)
            return 1e9;
        
        if(memo[row][col] != -1)
            return memo[row][col];
        
        int up = grid[row][col] + solve(grid, row-1, col, memo);
        int left = grid[row][col] + solve(grid, row, col-1, memo);
        return memo[row][col] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>memo(m, vector<int>(n, -1));
        return solve(grid, m-1, n-1, memo);
    }
};