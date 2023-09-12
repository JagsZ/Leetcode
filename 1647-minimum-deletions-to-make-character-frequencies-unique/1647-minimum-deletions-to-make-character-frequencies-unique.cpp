class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> map;
        unordered_set<int> set;
        int ans=0;
        
        for(auto x : s)
            map[x]++;
        
        
        for(auto x : map){
            int freq = x.second;
            if(set.find(freq) != set.end()){
                while(freq > 0){
                    if(set.find(freq) == set.end()){
                        break;
                    }
                    ans++;
                    freq--;
                }
            }
            if(freq !=0)
                set.insert(freq);
        }
        return ans;
    }
};