class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, ind1 = 0, ind2 = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        while(ind1 < s.size() && ind2 < g.size()){
            if(s[ind1] >= g[ind2]){
                ans++;
                ind2++;
            }
            ind1++;
        }
        return ans;
    }
};