int row[8] = {0,1,1, 1, 0, -1, -1,-1};
int col[8] = {1,1,0,-1, -1, -1, 0, 1};
int m, n;
typedef pair<int, int> pii;
class Solution {
    int bfs(vector<vector<int>>& grid, vector<vector<int>> &vis){
        int count=0, path=-1;
        queue<pii> q;
        
        if(grid[0][0] == 1)
            return path;
        q.push({0,0});
        vis[0][0] = 1;
        
        while(!q.empty()){
            pii cell = q.front();
            q.pop();
            
            if(cell.first == m-1 && cell.second == n-1){
                path= vis[cell.first][cell.second];
                break;
            }
                
            for(int i=0; i<8; i++){
                int adjx = cell.first + row[i];
                int adjy =  cell.second + col[i];
                
                if((adjx < m && adjx >=0) && (adjy < n && adjy >=0) &&
                  vis[adjx][adjy] == 0 && grid[adjx][adjy] == 0){
                    q.push({adjx, adjy});
                    vis[adjx][adjy] = vis[cell.first][cell.second]+1;
                }
            }
        }
        return path;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n , 0));
        return bfs(grid, vis);
    }
};