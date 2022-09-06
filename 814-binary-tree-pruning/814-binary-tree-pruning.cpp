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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        if(root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        
        TreeNode *left = pruneTree(root->left);
        TreeNode *right = pruneTree(root->right);
        
        
        root->left = left;
        root->right = right;
        
        if(root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        
        return root;
    }
};