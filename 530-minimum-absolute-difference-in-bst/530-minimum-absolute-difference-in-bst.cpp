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
public:
     vector<int> inorderNodes;

    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        // Store the nodes in the list.
        inorderNodes.push_back(node->val);
        inorderTraversal(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);

        int minDifference = INT_MAX;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDifference = min(minDifference, inorderNodes[i] - inorderNodes[i - 1]);
        }

        return minDifference;
    }
};