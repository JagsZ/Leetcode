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
    bool solve(TreeNode *root, int k, set<int> &s){
        if(root == NULL)
            return false;
        
        if(s.count(k - root->val))
            return true;
        
        s.insert(root->val);
        if(solve(root->left, k, s) == true)
            return true;
        if(solve(root->right, k, s) == true)
            return true;
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return solve(root, k, s);
    }
};