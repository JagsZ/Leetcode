class Solution {
    bool bfs(int s, vector<vector<int>> &adj, vector<int> &color){
        queue<int> q;
        q.push(s);
        color[s] = 1;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(int n_node : adj[v]){
                if(color[n_node] == -1){
                    color[n_node] = 1 - color[v];
                    q.push(n_node);
                }else{
                    if(color[n_node] == color[v])
                        return false;
                }
            } 
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, -1);
        vector<vector<int>> adj(n+1, vector<int>());
        
        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(bfs(i, adj, color) ==  false)
                    return false;
            }
        }
        return true;
    }
};