class Solution {
    bool dfs(int v, vector<vector<int>> &adj, vector<int> &vis){
        vis[v] = true;
        
        for(auto x : adj[v]){
            if(vis[x] == -1){
                if(dfs(x, adj, vis) == false)
                    return false;
            } else if(vis[x] == 1){
                return false;
            }
        }
        vis[v] =  2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> vis(numCourses, -1);

        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == -1){
                if(dfs(i, adj, vis) == false)
                    return false;
            }
        }
        return true;
    }
};