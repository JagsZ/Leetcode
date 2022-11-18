class Solution {
    int keepDividing(int n , int divisor){
        while(n % divisor == 0){
            n /= divisor;
        }
        return n;
    }
public:
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        
        for(auto factor : {2,3,5}){
            n = keepDividing(n, factor);
        }
        return n == 1;
    }
};