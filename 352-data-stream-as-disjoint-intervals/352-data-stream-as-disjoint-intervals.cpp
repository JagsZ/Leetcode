class SummaryRanges {
    set<int> range;
public:
    SummaryRanges() {
    
    }
    
    void addNum(int value) {
        range.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(range.empty())
            return {};
        
        vector<vector<int>> ans;
        int l = -1, r = -1;
        for(auto val : range){
            if(l < 0){
                l = r = val;
            }else if(val == r+1){
                r = val;
            }else{
                ans.push_back({l, r});
                l = r = val;
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */