class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> stops(n , INT_MAX);
        
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            vector<int> info = pq.top();
            int node = info[1];
            int node_dist = info[0];
            int steps = info[2];
            pq.pop();
            
            if(steps > stops[node] || steps > k+1) continue;
            stops[node] = steps;
            if(node == dst) return node_dist;
            for(auto nbr : adj[node]){
                int nbr_node = nbr.first;
                int nbr_dist = nbr.second;
                pq.push({node_dist+nbr_dist, nbr_node, steps+1});
            }
        }
        return -1;
    }
};