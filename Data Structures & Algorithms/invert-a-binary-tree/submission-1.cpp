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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*>qe;
        qe.push(root);
        while(!qe.empty()){
            TreeNode * node=qe.front();
            qe.pop();
            swap(node->left,node->right);
            if(node->left)qe.push(node->left);
            if(node->right)qe.push(node->right);
        }
        return root;
    }
};
