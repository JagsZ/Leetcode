class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cout.tie(0);
        cin.tie(0);
        int m = grid.size(), n = grid[0].size();
        int rows[m], cols[n]; 
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = m - 2 * rows[i] + n - 2 * cols[j];
            }
        }
        return grid;
    }
};  