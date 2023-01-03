class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i+1][0] <= intervals[i][1]){
                int start = intervals[i][0];
                int end = intervals[i][1];
                while(i < n-1 && intervals[i+1][0] <= end){
                    end = max(end, intervals[i+1][1]);
                    i++;
                }
                ans.push_back({start, end});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};