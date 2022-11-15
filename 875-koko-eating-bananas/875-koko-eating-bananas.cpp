class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN;
        
        for(int i = 0; i < piles.size(); i++){
            l = min(l, piles[i]);
            r = max(r, piles[i]);
        }
        
        while( l < r){
            int mid = (l+r)/2;
            int min_hour = 0;
           
            for(auto x : piles){
                min_hour += (x / mid) + (x % mid != 0);
                if(min_hour > h)
                    break;
            }
            if(min_hour <= h){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};