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
private:
    void flat(TreeNode* root, TreeNode** head) {
        if(root == nullptr)
            return;
        
        (*head)->right = root;
        *head = (*head)->right;
        
        TreeNode* leftNodes = root->left;
        TreeNode* rightNodes = root->right;
        root->left = nullptr;
        root->right = nullptr;
        
        flat(leftNodes, head);
        flat(rightNodes, head);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* head1 = new TreeNode(-1);
        TreeNode* head = head;
        flat(root, &head);
        
        root = head1->right;
    }
};