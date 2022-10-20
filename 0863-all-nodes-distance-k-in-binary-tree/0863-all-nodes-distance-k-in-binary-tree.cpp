/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void createList(TreeNode *root, TreeNode *parent, unordered_map<int, vector<int>> &adj){
        if(root == NULL)
            return;
        if(parent != NULL){
            adj[parent->val].push_back(root->val);
            adj[root->val].push_back(parent->val);
        }
        createList(root->left, root, adj);
        createList(root->right, root, adj);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> vis;
        if(k == 0)
            return {target->val};
        
        createList(root, NULL, adj);
        vector<int> ans;
        vis.insert(target->val);
        
        for(auto x : adj[target->val]){
            queue<pair<int, int>> q;
            q.push({x, 1});
            vis.insert(x);
            
            while(!q.empty()){
                int node  = q.front().first;
                int dist = q.front().second;
                q.pop();
                
                if(dist == k){
                    ans.push_back(node);
                }
                
                for(auto ng : adj[node]){
                    if(!vis.count(ng)){
                        q.push({ng, dist+1});
                        vis.insert(ng);
                    }
                }
            }
        }
        return ans;
    }
};