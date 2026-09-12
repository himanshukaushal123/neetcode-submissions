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
    int maxi=INT_MIN;
    int maxDepth(TreeNode* root){
        if(root==NULL)return 0;
        int lh=1+maxDepth(root->left);
        int rh=1+maxDepth(root->right);
        maxi=max(maxi,lh+rh-2);
        return max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_depth=maxDepth(root);
        return maxi;
    }
};
