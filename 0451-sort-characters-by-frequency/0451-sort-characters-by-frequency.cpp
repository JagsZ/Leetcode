class Solution {

public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        
        for(auto x : s)
            freq[x]++;
        
        for(auto x : freq)
            pq.push({x.second, x.first});
        
        while(!pq.empty()){
            int index = 0;
            pair<int, char> pi = pq.top();
            pq.pop();
            while(index < pi.first){
                ans += pi.second;
                index++;
            }
        }
        return ans;
    }
};