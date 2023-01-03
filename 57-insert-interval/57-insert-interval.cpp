class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0)
            ans.push_back(newInterval);
        
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
                if(i == n-1)
                    ans.push_back(newInterval);
                    
            }else{
                if(newInterval[1] < intervals[i][0]){
                    ans.push_back(newInterval);
                    while(i < n){
                        ans.push_back(intervals[i]);
                        i++;
                    }
                }else{
                    int start = min(intervals[i][0], newInterval[0]);
                    while(i < n && intervals[i][0] <= newInterval[1]){
                        i++;
                    }
                    int end = max(newInterval[1], intervals[i-1][1]);
                    ans.push_back({start, end});
                    while(i < intervals.size()){
                        ans.push_back(intervals[i]);
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};