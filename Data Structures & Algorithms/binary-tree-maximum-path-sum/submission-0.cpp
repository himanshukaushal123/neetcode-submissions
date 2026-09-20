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
    int maxi = INT_MIN;

    int solve(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        // Best path passing through current node
        int currentPath = root->val + left + right;

        maxi = max(maxi, currentPath);

        // Give parent only ONE branch
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
