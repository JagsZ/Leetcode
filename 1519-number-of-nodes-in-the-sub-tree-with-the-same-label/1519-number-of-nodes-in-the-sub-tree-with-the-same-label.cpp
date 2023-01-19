class Solution {
    vector<int> dfs(int node, int parent, vector<vector<int>> &adj, string &labels, vector<int> &ans){
        
        vector<int> count(26, 0);
        count[labels[node] - 'a'] = 1;
        
        for(int child : adj[node]){
            if(child == parent)
                continue;
            vector<int> child_count = dfs(child, node, adj, labels, ans);
            for(int i = 0; i < 26; i++){
                count[i] += child_count[i];
            }
        }
        ans[node] = count[labels[node] - 'a'];
        return count;
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> ans(n, 0);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj, labels, ans);
        return ans;
    }
};