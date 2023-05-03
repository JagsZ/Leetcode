class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        unordered_set<int> s11, s22;
        vector<vector<int>> ans(2, vector<int>());
        
        for(auto x : nums1)
            s1.insert(x);
        for(auto x : nums2)
            s2.insert(x);
        
        for(int i = 0; i < nums1.size(); i++){
            if(s2.find(nums1[i]) == s2.end() && s11.find(nums1[i]) == s11.end()){
                ans[0].push_back(nums1[i]);
                s11.insert(nums1[i]);
            }
        }
        
        for(int i = 0; i < nums2.size(); i++){
            if(s1.find(nums2[i]) == s1.end() && s22.find(nums2[i]) == s22.end()){
                ans[1].push_back(nums2[i]);
                s22.insert(nums2[i]);
            }
        }
        return ans;
    }
};