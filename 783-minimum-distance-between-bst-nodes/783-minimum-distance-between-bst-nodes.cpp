/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode *root, vector<int> &nums){
        if(root == NULL)
            return;
        
        nums.push_back(root->val);
        solve(root->left, nums);
        solve(root->right, nums);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        int min_diff = INT_MAX; 
        solve(root, nums);
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-1; i++){
            min_diff = min(min_diff, (nums[i+1] - nums[i]));
        }
        return min_diff;
    }
};