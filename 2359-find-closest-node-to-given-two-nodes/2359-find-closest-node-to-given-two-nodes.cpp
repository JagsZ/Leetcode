class Solution {
    void findPath(int node, vector<bool> &vis, vector<int> &edges, vector<int>&path){
        
        vis[node] = true;
          
        int neighbour = edges[node];
        if(neighbour != -1 && vis[neighbour] == false){
            path[neighbour] = path[node] + 1;
            findPath(neighbour, vis, edges, path);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = -1, dis = INT_MAX;
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);
        vector<int> node1_path(n, 0);
        vector<int> node2_path(n, 0);
        
        
        findPath(node1, vis1, edges, node1_path);
        findPath(node2, vis2, edges, node2_path);
        
        for(int i = 0; i < n; i++ ){
           if(vis1[i] && vis2[i]){
               if(dis > max(node1_path[i], node2_path[i])){
                   ans = i;
                   dis = max(node1_path[i], node2_path[i]);
               }
           }
        }
        return ans;
    }
};