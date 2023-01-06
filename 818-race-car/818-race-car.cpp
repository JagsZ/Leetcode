

class Solution {
struct hash{
  size_t operator() (const pair<int, int> &x) const
  {
      return x.first ^ x.second;
  }
};

public:
    int racecar(int target) {
        int ans = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 1}});
        unordered_set<pair<int, int>, hash> vis;
        
        while(!q.empty()){
            int moves = q.front().first;
            int pos = q.front().second.first;
            long long spd = q.front().second.second;
            q.pop();
            
            if(pos == target){
                ans = moves;
                break;
            }
            
            if(vis.find({pos, spd}) == vis.end()){
                vis.insert({pos, spd});
                
                int curr_pos = pos + spd;
                long long curr_spd = 2*spd;
                q.push({moves+1, {curr_pos, curr_spd}});
                if((curr_pos > target && curr_spd > 0) || (curr_pos < target && curr_spd < 0)){
                    curr_spd = spd > 0? -1 : 1;
                    q.push({moves+1, {pos, curr_spd}});
                }
            }
            
        }
        return ans;
    }
};