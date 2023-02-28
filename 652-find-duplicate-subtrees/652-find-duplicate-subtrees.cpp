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
    string duplicate(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mp) {
        if(!root) return "";
        string s = "(" + duplicate(root->left, mp) + to_string(root->val) + duplicate(root->right, mp) + ")";
        mp[s].push_back(root);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> mp;
        vector<TreeNode*> res;
        duplicate(root, mp);
        for(auto m : mp) {
            if(m.second.size() > 1)
                res.push_back(m.second[0]); 
        }
        return res;
    }
};