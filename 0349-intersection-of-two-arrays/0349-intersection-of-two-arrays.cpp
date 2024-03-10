class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_set<int> set1;
        vector<int> ans;
        for(auto x : nums1)
            set.insert(x);
        for(auto x : nums2)
            set1.insert(x);
        for(auto x : set1){
            if(set.find(x) != set.end()){
                ans.push_back(x);
            }
        }
        return ans;
    }
};