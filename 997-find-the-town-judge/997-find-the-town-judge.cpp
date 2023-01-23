class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> adj(n+1, unordered_set<int>());
        int judge = -1;
        
        for(int i = 0; i < trust.size(); i++){
            adj[trust[i][0]].insert(trust[i][1]);
        }
        
        for(int i = 1; i <= n; i++){
            if(adj[i].size() == 0){
                judge = i;
                for(int j = 1; j <= n; j++){
                    if( j != i){
                        if(adj[j].find(i) == adj[j].end()){
                            judge = -1;
                            break;
                        }
                    }
                }
            }
        }
        return judge;
    }
};