class Solution {
public:
    int arraySign(vector<int>& nums) {
        int mul=1;
        for( auto x: nums){
            if(x==0)
                return x;
            mul*= (x/abs(x));
        }
        return mul;
    }
};