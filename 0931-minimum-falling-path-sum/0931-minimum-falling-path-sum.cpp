class Solution {
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo){
        
        if(col < 0 || col >= matrix[0].size())
            return 1e9;
        
        if(row == 0)
            return matrix[row][col];
        
        if(memo[row][col] != -1)
            return memo[row][col];
        
        int st = matrix[row][col] + solve(matrix, row-1, col, memo);
        int left = matrix[row][col] + solve(matrix, row-1, col-1, memo);
        int right = matrix[row][col] + solve(matrix, row-1, col+1, memo);
        int path_sum  = min(st, min(left, right));
        return memo[row][col] = path_sum;
    }
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), min_sum = 1e9;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        
        }
        
        for( int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int down = matrix[i][j] + dp[i-1][j];
                int ld = 1e9, rd = 1e9;
                if( j == 0)
                    ld = 1e9;
                else
                    ld = matrix[i][j] + dp[i-1][j-1];
            
                if(j == n-1)
                    rd = 1e9;
                else
                    rd = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(down, min(ld, rd));
             }
        }
        for(int j = 0; j < n; j++){
            min_sum = min(min_sum, dp[n-1][j]);
        }
        return min_sum;
    }
};