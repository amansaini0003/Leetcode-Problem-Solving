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
void getPredecessor(TreeNode* root, TreeNode* p, TreeNode** pre){
    if(root == nullptr){
        return ;
    }
    if(root->val < p->val){
        *pre = root;
         getPredecessor(root->right, p, pre);
    } else {
        getPredecessor(root->left, p, pre);
    }
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        } else if(key > root->val){
            root->right = deleteNode(root->right, key);
        } else if(key == root->val) {
            if(root->left == nullptr && root->right == nullptr)
                return nullptr;
            if(root->left == nullptr){
                return root->right;
            }
            if(root->right == nullptr){
                return root->left;
            }
            
            TreeNode *pre = nullptr;
            getPredecessor(root, root, &pre);

            pre->right = root->right;
            root->right = nullptr;
            return root->left;
            
        }
        return root;
    }
};