class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l =  *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        
        while(l < r){
            int mid = (l+r)/2;
            int t_day = 0, sum = 0;
            
            for(int i = 0; i < n; i++){
                sum += weights[i];
                if(sum > mid){
                    t_day++;
                    sum = weights[i];
                }
                else if(sum == mid){
                    t_day++;
                    sum = 0;
                }
            }
            if(sum)
                t_day++;
            if(t_day > days){
                l = mid+1;
            }else{
                 r = mid;
            }
        }
        return r;
    }
};