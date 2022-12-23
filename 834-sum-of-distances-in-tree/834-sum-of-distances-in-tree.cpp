class Solution {
    int dfs(int v, int par, vector<vector<int>> &adj, vector<int> &subtree){
        int curr = 0;
        for(auto u : adj[v]){
            if(u != par){
                curr+= dfs(u, v, adj, subtree);
                curr += subtree[u];
                subtree[v] += subtree[u];
            }
        }
        return curr;
    }
    void dfs(int v, int par, vector<vector<int>> &adj, vector<int> & subtree, 
             int root_ans, vector<int> &ans){
        ans[v] = root_ans;
        
        for(auto u : adj[v]){
            if(u != par){
                dfs(u, v, adj, subtree, (root_ans - subtree[u] + (subtree[0]) - subtree[u]), ans);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> ans(n, 0);
        vector<int> subtree(n, 1);
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int root_ans = dfs(0, -1,adj, subtree);
        dfs(0, -1, adj, subtree, root_ans, ans);
        return ans;
    }
};