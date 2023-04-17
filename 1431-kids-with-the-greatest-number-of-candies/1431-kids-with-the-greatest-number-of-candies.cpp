class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_val = 0, n = candies.size();
        vector<bool> ans(n, false);
        max_val = *max_element(candies.begin(), candies.end());
        
        for(int i = 0; i < n; i++){
            if((candies[i] + extraCandies) >= max_val){
                ans[i] = true;
            }
        }
        return ans;
    }
};