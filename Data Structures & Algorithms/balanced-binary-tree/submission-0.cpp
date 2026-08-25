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
    int dfs(TreeNode* root, bool& ans){
        if (root==nullptr) return 0;
        int left = 1 + dfs(root->left,ans);
        int right = 1 + dfs(root->right,ans);
        if (abs(right-left)>1) ans = false;
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;
        bool ans = true;
        dfs(root,ans);
        return ans;
    }
};
