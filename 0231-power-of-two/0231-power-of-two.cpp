class Solution {
public:
    bool isPowerOfTwo(int n) {
        int one_bit = false;
        if(n <= 0)
            return false;
        while(n > 0){
            if(one_bit && (n & 1))
                return false;
            if(n & (n & 1))
                one_bit = true;
            n = n >> 1;
        }
        return true;
    }
};