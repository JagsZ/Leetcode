class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(set.find(s[i]) != set.end()){
                set.clear();
                set.insert(s[i]);
                ans++;
                continue;
            }
            set.insert(s[i]);
            
        }
        ans++;
        return ans;
    }
};