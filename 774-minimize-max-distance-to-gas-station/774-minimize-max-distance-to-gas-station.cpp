class Solution {
    bool isSufficient(double mid, vector<int> &stations, int k){
        int used = 0;
        for(int i = 0; i < stations.size()-1; i++){
            used += (int)((stations[i+1] - stations[i])/mid);
        }
        return used <= k;
    }
    
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double l = 0, r = 1e6;
        
        while((r - l) > 1e-6){
            double mid = (l+r)/2.0;
            if(isSufficient(mid, stations, k)){
                r = mid;
            }else{
                l=mid;
            }
        }
        return r;
    }
};