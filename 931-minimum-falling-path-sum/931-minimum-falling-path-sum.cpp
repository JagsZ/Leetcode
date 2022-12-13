class Solution {
    int dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &memo){
        
        if(col < 0 || col >= matrix[0].size())
            return 1e9;
        
        if(row == 0)
            return matrix[row][col];
        
        if(memo[row][col] != -1)
            return memo[row][col];
            
        int right = matrix[row][col] + dfs(row-1, col+1, matrix, memo);
        int st = matrix[row][col] + dfs(row-1, col, matrix, memo);
        int left = matrix[row][col] + dfs(row-1, col-1, matrix, memo);
        return memo[row][col] = min(st, min(left, right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int min_val = 1e9;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        
        for(int col = 0; col < n; col++){
            min_val = min(min_val, dfs(m-1, col, matrix, memo));
        }
        return min_val;
    }
};