class Solution {
    bool dfs(int s, int d, vector<vector<int>> &adj_list, vector<bool> &vis){
        vis[s] = true;
        
        if(s == d)
            return true;
        
        vector<int> list =  adj_list[s];
        for(auto x : list){
            if(vis[x] == false){
                vis[x] =  true;
                if(dfs(x, d, adj_list, vis) == true)
                    return true;
            }
        }
        return false;
            
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n, vector<int>());
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<bool> vis(n, false); 
        return dfs(source, destination, adj_list, vis);
    }
};