class Solution {
    void dfs(int start, vector<vector<int>> &adj, vector<bool> &vis){
        vis[start] = true;
        
        for(int x : adj[start]){
            if(vis[x] == false){
                dfs(x, adj, vis);
            }
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                count++;
                dfs(i, adj, vis);
            }
        }
        return (n - count);
    }
};