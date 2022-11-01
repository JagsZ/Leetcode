class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        unordered_map<int, int> umap;
        int val =0;

        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]] = i;
        }
        for(int i =0; i<nums.size();i++){
            val = target - nums[i];
            if(umap[val] && umap[val] != i){
                out.push_back(i);
                out.push_back(umap[val]);
                break;
            }

        }
    return out;
    }
};