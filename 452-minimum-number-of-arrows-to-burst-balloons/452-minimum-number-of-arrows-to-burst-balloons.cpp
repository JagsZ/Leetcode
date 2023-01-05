class Solution {
    bool static cmp(vector<int> &a, vector<int> &b){
        return b[1] > a[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), count = 1;
        
        sort(points.begin(), points.end(), cmp);
        int start = points[0][1];
        
        for(int i = 0; i < n-1; i++){
            if(start < points[i+1][0]){
                count++;
                start = points[i+1][1];
            }
        }
        return count;
    }
};