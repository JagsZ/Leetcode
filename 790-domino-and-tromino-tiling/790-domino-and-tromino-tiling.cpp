class Solution {
    int mod = 1000000007;
public:
    int numTilings(int n) {
        long f1 = 1, f2 = 2, f3 = 0, p1 = 1, p2 = 0, curr = 0;
        if(n == 1)
            return f1;
        
        if(n == 2)
            return f2;
        
        for(int i = 3; i <= n; i++){
            f3 = (f1 + f2 + (2*p1)) % mod;
            p2 = (p1 + f1) % mod;
            p1 = p2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};