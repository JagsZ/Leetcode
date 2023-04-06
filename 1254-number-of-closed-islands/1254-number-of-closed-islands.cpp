int adj_row[] = {-1, 0, 1, 0};
int adj_col[] = {0, 1, 0, -1};
class Solution {
    bool isValid(int row, int col, vector<vector<int>> &grid, int m, int n, vector<vector<bool>> &vis){
        
        vis[row][col] = true;
        
        if(((row == 0 || row == m-1) && grid[row][col] == 0) ||
           ((col == 0 || col == n-1) && grid[row][col] == 0))
            return false;
        
        bool valid =  true;
        for(int i = 0; i < 4; i++){
            int nrow = adj_row[i] + row;
            int ncol = adj_col[i] + col;
            if((nrow >= 0 && nrow < m) && (ncol >=0 && ncol < n) && vis[nrow][ncol] == false &&
              grid[row][col] == 0){
                valid &= isValid(nrow, ncol, grid, m, n, vis);
            }
         }
         return valid;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(grid[i][j] == 0 && vis[i][j] == false){
                    if(isValid(i, j, grid, m, n, vis)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};