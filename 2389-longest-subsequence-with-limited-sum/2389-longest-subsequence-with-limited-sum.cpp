class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < queries.size(); i++){
            int l = 0, r = nums.size()-1, sum=0; 
            while( l <= r){
                if( sum + nums[l] <= queries[i]){
                    sum += nums[l];
                    l++;
                }else{
                    break;
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};