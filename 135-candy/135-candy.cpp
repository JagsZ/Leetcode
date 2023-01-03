class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0, n = ratings.size();
        vector<int> candi(n, 1);
        
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1])
                candi[i] = candi[i-1]+1;
        }
        ans = candi[n-1];
        for(int i = n-2; i >=0; i--){
            if(ratings[i] > ratings[i+1])
                candi[i] = max(candi[i], candi[i+1]+1);
            ans += candi[i];
        }
        return ans;
    }
};