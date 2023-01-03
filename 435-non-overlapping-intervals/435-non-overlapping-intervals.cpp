class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return b[1] > a[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), count = 1, end = 0;
    
        if(n == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
                count++;
            }
        }
        return n - count;
    }
};