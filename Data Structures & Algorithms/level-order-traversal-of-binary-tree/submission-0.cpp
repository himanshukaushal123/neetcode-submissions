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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL)return ans;
        queue<TreeNode *>qe;

        qe.push(root);
        while(!qe.empty()){
            int size=qe.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode * node=qe.front();
                qe.pop();
                temp.push_back(node->val);
                if(node->left)qe.push(node->left);
                if(node->right)qe.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
