class Solution {
public:
    double myPow(double x, int n) {
    
        long long n_val = n;
        
        if(n == 0)
            return 1.0;
        
        if(n_val < 0){
            x = 1 / x;
            n_val = -n_val;
        }
        double ans = 1;
        double curr = x;
        for(long long i = n_val; i; i /= 2){
            if((i % 2) == 1)
                ans = ans * curr;
            curr *= curr;
        }
        return ans;
    }
};