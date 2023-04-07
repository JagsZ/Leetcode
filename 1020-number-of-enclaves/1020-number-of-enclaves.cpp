int adj_row[] = {-1, 0, 1, 0};
int adj_col[] = {0, 1, 0, -1};

class Solution {
    void isValid(int row, int col, vector<vector<int>> &grid, int m, int n, 
                    vector<vector<bool>> &vis){
        
        vis[row][col]  = true;
        
        bool status = true;
        for(int i = 0; i < 4; i++){
            int nrow = adj_row[i] + row;
            int ncol = adj_col[i] + col;
            if((nrow >= 0 && nrow < m) && (ncol >= 0 && ncol < n) && grid[nrow][ncol] == 1 &&
              vis[nrow][ncol] == false){
                 isValid(nrow, ncol, grid, m, n, vis);
            }
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0, ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == false &&
                  ((i == 0 || i == m-1) || (j == 0 || j == n-1))){
                    isValid(i, j, grid, m, n, vis);
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == false)
                    count++;
            }
        }
        return count;
    }
};