class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        int n  = nums.size();
        
        for(int i = (2*n-1); i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(!st.empty())
                ans[i % n] = st.top();
            else
              ans[i % n] = -1;
            st.push(nums[i % n]);
        }
        return ans;
    }
};