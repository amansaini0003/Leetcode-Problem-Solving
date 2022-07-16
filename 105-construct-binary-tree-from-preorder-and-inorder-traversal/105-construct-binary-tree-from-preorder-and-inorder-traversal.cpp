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
    int preorderIndex;
    unordered_map<int, int> mp;

    TreeNode* arrayToTree(vector<int> &pre, int left, int right){
        if(left > right)
            return nullptr;
        
        int rootVal = pre[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = arrayToTree(pre, left, mp[rootVal]-1);
        root->right = arrayToTree(pre, mp[rootVal]+1, right);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& inorder) {
        preorderIndex = 0;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]  = i;
        }
        TreeNode *root = arrayToTree(pre, 0, pre.size()-1);
        return root;
    }
};