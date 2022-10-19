class Solution {
    static bool comparator(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second>p2.second || (p1.second==p2.second && p1.first<p2.first))
            return true;
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        vector<pair<string,int>> freq; 
        vector<string> out;

        int n = words.size();

        for(int i=0; i<n; i++){
            um[words[i]] +=1; 
        }
        for(auto x : um)
            freq.push_back({x.first,x.second});

        sort(freq.begin(),freq.end(),comparator);

        for(int i=0; i<k && (i < freq.size()); i++){
            pair<string,int> tmp;
            tmp = freq[i];
            out.push_back(tmp.first);
        } 
        return out;
    }
};