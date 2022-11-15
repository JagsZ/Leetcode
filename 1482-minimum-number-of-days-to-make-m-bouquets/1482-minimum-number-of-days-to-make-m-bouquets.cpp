class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k)
            return -1;
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while( l < r){
            int mid = (l+r)/2;
            int bou = 0, count = 0;;
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= mid){
                    count++;
                }else{
                    count = 0;
                }
                if(count != 0 && count % k == 0){
                    bou++;
                    count = 0;
                }
            }
            if(bou >= m){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};