class Solution {
public:
    int tribonacci(int n) {
        int ans = 0, n0 = 0, n1 = 1, n2 = 1;
        
        if(n == 0)
            return n0;
        
        if(n == 1 | n == 2)
            return n2;
        
        for(int i = 3; i<= n; i++){
            int n3 = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = n3;
        }
        return n2;
    }
};