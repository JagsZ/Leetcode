class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        
        for(auto x : nums){
            freq[x]++;
        }
        
        for(auto x : freq){
            pq.push({x.second, x.first});
        }
        
        while(k > 0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};