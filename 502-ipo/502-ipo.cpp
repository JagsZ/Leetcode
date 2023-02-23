class Solution {

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pc;
        int ans = w;
        int n = profits.size();
        
        for(int i = 0; i < n; i++){
            pc.push_back({capital[i], profits[i]});
        }
        sort(pc.begin(), pc.end());
        priority_queue<int> pq;
        int ptr = 0;
        for(int i = 0; i < k; i++){
            while(ptr < n && pc[ptr].first <= ans){
                pq.push(pc[ptr++].second);
            }
            if(pq.empty())
                break;
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};