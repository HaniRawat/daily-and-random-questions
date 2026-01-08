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
    static const int MOD = 1e9 + 7;
    long long ans = 0;

    long long dfs(TreeNode* root) {
        if(!root)   return 0;

        root->val += dfs(root->left) + dfs(root->right);
        return root->val;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);    

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(!front)  continue;

            ans = max(ans, front->val * (total - front->val));

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return ans % MOD;
    }
};