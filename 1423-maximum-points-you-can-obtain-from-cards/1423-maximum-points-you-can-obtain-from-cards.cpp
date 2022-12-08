class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long total_sum = 0;
        int n_k = (n - k);
        int p1 = 0, p2 = 0, sum = 0, min_sum = 1e9;
        for(auto x : cardPoints)
            total_sum += x;

        while(p1 < n){
            if((p1 - p2 + 1) <= n_k){
                sum += cardPoints[p1];
            }else{
                min_sum = min(sum, min_sum);
                sum += (cardPoints[p1] - cardPoints[p2]);
                p2++;
            }
            p1++;
        }
        min_sum = min(sum, min_sum);
        return total_sum - min_sum;
    }
};