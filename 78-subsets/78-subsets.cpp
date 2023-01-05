class Solution {
   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> out;
        int n = nums.size();
        int subset = pow(2, n);
        
        for(int count = 0; count < subset; count++){
            int i = 0;
            while(i < n){
                if(count & (1 << i))
                    out.push_back(nums[i]);
                i++;
            }
            list.push_back(out);
            out.resize(0);
        }
        return list;
    }
};