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
    TreeNode *solve(vector<int> &postorder, int in_start, int in_end, unordered_map<int, int> &map){
        if(in_start > in_end)
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[idx]);
        idx--;
        root->right = solve(postorder, map[root->val] + 1, in_end, map);
        root->left = solve(postorder, in_start, map[root->val]-1, map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        idx = postorder.size()-1;
        
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        TreeNode *root = solve(postorder, 0, inorder.size()-1, map);
        return root;
    }
};