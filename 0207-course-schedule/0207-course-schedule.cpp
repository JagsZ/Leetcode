class Solution {
  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indigree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;
        vector<int> topo;
        
        for(auto x : prerequisites)
            adj[x[0]].push_back(x[1]);
        
      for(int i = 0; i < numCourses; i++){
          for( auto it: adj[i]){
              indigree[it]++;
          }
      }
        
      for(int i = 0; i < numCourses; i++){
            if(indigree[i] == 0)
                q.push(i);
      }
        
      while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
            
        for(auto it : adj[node]){
            indigree[it]--;
            if(indigree[it] == 0)
                q.push(it);
            }
        }
        return topo.size() == numCourses? true: false;
    }
};