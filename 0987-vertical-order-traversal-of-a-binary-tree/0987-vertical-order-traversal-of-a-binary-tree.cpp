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
      class Compare{
     public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.second != b.second)
                return (a.second > b.second);
            return (a.first > b.first);
        }
    };
       
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
   
        map<int, map<int, multiset<int>>> node_map;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        
        q.push({root, {0,0}});
        
        while(q.size() > 0){
            TreeNode *node = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            
            q.pop();
            
            node_map[col][row].insert(node->val);
            if(node->left != NULL)
                q.push({node->left,{col-1, row+1}});
            if(node->right != NULL)
                q.push({node->right, {col+1, row+1}});
        }       
        for(auto x : node_map){
            vector<int> col;
            for(auto y : x.second){
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};