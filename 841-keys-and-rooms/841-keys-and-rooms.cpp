class Solution {
    void dfs(int start, vector<vector<int>> &adj_list, vector<bool> &vis){
        vis[start] = true;
        vector<int> list = adj_list[start];
        for(int x : list){
            if(vis[x] == false){
                dfs(x,adj_list, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size();
        vector<bool> vis(m, false);
          
        dfs(0, rooms, vis);
        for(int i = 0; i < m; i++){
            if(vis[i] == false)
                return false;
        }
        return true;
    }
};