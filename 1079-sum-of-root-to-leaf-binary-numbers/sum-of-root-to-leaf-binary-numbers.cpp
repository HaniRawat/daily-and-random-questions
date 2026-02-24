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

    int solve(TreeNode* root, int ans) {
        if(!root)   return 0;
        // ans = ans * 2 + root->val;
        ans = (ans << 1) | root->val;

        if(root->left == root->right)   return ans;
        return solve(root->left, ans) + solve(root->right, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};