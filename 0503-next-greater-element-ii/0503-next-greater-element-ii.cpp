class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        
        for(int i = (2*nums.size()-1); i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i % nums.size()]){
                st.pop();
            }
            if(!st.empty())
                ans[i % nums.size()] = nums[st.top()];
            else
              ans[i % nums.size()] = -1;
            st.push(i % nums.size());
        }
        return ans;
    }
};