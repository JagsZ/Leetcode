class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> cells;
        vector<int> col;
        
        for(int i = 0; i < n; i++)
            col.push_back(i);
        
        cells.push_back({0,0});
        for(int i = n-1; i >= 0; i--){
            for(auto j : col){
                cells.push_back({i, j});
            }
            reverse(col.begin(), col.end());
        }
        
        vector<int> dist(n*n + 1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int next = curr+1; next <= min(curr+6, n*n); next++){
                auto[row, column] = cells[next];
                int dest = board[row][column] != -1 ? board[row][column] : next;
                if(dist[dest] == -1){
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
            
        }
        return dist[n*n];
        
    }
};