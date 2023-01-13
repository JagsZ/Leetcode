class Solution {
    
    int dfs(int v, int parent, vector<vector<int>> &adj, string &s, int &max_path){
        
        int long1 = 0, long2 = 0;
        
        for(auto child : adj[v]){
            if(child == parent)
                continue;
            int path = dfs(child, v, adj, s, max_path);
            
            if(s[child] == s[v])
                continue;
            
            if(path > long2)
                long2 = path;
            if(long2 > long1)
                swap(long1, long2);
        }
        int result = long1+long2+1;
        int child = max(long1, long2) + 1;
        int root = 1;
        max_path = max(max_path, result);
        max_path = max(max_path, child);
        max_path = max(max_path, root);
        return max(child, root);
        
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), max_path = 0;
        vector<vector<int>> adj(n, vector<int>());
        
        for(int i = 1; i < n; i++){
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, adj, s, max_path);
        return max_path;
    }
};