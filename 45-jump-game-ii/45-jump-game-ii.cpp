class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size(), jumps = 0, far = 0, curr = 0;
       
        for(int i = 0; i < n-1; i++){
            far = max(far, nums[i] + i);
            if(i == curr){
                jumps++;
                curr = far;
            }
        }
        return jumps;
    }
};