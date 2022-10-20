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
    int idx = 0;
    TreeNode *solve(vector<int> &preorder, int in_start, int in_end, unordered_map<int, int> &map){
        if(in_start > in_end)
            return NULL;
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        
        root->left = solve(preorder, in_start, map[root->val]-1, map);
        root->right = solve(preorder, map[root->val]+1, in_end, map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        TreeNode *root = solve(preorder, 0, preorder.size()-1, map);
        return root;
    }
};