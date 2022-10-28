class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    unordered_map<string, vector<string>> ummap;
    vector<vector<string>> out;
    string s;

    for(int i=0; i<strs.size(); i++){
        s = strs[i];
        sort(s.begin(), s.end());
        ummap[s].push_back(strs[i]);
    }
    for(auto &x :ummap)
        out.push_back(x.second); 
    return out;
    }
};