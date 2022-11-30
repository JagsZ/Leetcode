class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        for(auto x : arr)
            map[x]++;
        
        for(auto x : map){
            if(set.find(x.second) != set.end())
                return false;
            set.insert(x.second);
        }
        return true;
    }
};