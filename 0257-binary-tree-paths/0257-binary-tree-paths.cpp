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
    void solve(TreeNode *root, string path, vector<string> &path_list){
        
        if(root != NULL){
            path += to_string(root->val);
            if(root->left == NULL && root->right == NULL){
                path_list.push_back(path);
            }else{
                path += "->";
                solve(root->left, path, path_list);
                solve(root->right, path, path_list);
            }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path_list;
        string path = "";
        solve(root, path, path_list);
        return path_list;
    }
};