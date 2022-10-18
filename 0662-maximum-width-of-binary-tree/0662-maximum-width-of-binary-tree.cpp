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
    void solve(TreeNode *root, int depth, unsigned int level, unordered_map<int, vector<unsigned int>> &map, unsigned int &ans){
        if(root == NULL)
            return;
        //int min_val = map[depth]
        map[depth].push_back(level);
        if(map.count(depth)){
            vector<unsigned int> vec = map[depth];
            ans = max(ans, vec[vec.size()-1] - vec[0] + 1);
        }
        for(auto x : map[depth])
            cout<< x << " ";
        cout<<endl;
        solve(root->left, depth+1, (2*level), map, ans);
        solve(root->right, depth+1, (2*level)+1, map, ans);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned int ans = 0;
        unordered_map<int, vector<unsigned int>> map;
        solve(root, 0, 0, map, ans);
        return ans;
    }
};