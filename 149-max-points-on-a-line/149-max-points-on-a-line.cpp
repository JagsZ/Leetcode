class Solution {
    
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 2, n = points.size();
        if(n == 1)
            return 1;
        for(int i = 0; i < n; i++){
            unordered_map<double, int> slope_map;
            for(int j = 0; j < n; j++){
                if(i != j){
                    double slope = 0;
                    slope = atan2((points[j][1] - points[i][1]),(points[j][0] - points[i][0]));
                    slope_map[slope]++;
                }
            }
            for(auto x : slope_map){
                ans = max(ans, x.second+1);
            }
        }
        return ans;
    }
};