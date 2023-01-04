class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> map;
        
        for(auto x : tasks)
            map[x]++;
        
        for(auto x : map){
            int freq = x.second;
            if(freq == 1)
                return -1;
            
            if( freq % 3 == 0){
                ans += (freq / 3);
            }else{
                ans += (freq / 3 + 1);
            }
            
        }
        return ans;
    }
};