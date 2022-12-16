class Solution {
    static bool cmp(int &a, int &b){
        return a > b;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        for(auto x: tasks)
            freq[x - 'A']++;
        
        sort(freq.begin(), freq.end(), cmp);
        int idle_time = (freq[0] - 1) * n;
        
        for(int i = 1; i < freq.size(); i++){
            if(freq[i] == 0)
                break;
            idle_time -= min(freq[0]-1, freq[i]);
        }
        idle_time = max(0, idle_time);
        return (idle_time + tasks.size());
    }
};