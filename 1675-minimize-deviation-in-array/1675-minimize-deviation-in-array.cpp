class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), nums_min=INT_MAX,min_dev=INT_MAX;;
        priority_queue<int> even;
        
        for(auto x: nums){
            int val=0;
            if(x%2 != 0){
                val=(2*x);
            }else{
                val = x;
            } 
            nums_min = min(nums_min, val);
            even.push(val);
        }
        
        while(!even.empty()){
            int val = even.top();
            even.pop();
            min_dev = min(min_dev, val - nums_min);
            if(val%2 == 0){
                val /= 2;
                even.push(val);
                nums_min = min(nums_min, val);
            }else{
                break;
            }
        }
        return min_dev;
    }
};