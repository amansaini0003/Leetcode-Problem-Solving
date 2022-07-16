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
    int postOrderIndex;
    unordered_map<int, int> mp;
    
    TreeNode* arrayToTree(int left, int right, vector<int> &postorder) {
        if(left > right)
            return nullptr;
        
        int rootVal = postorder[postOrderIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        root->right = arrayToTree(mp[rootVal] + 1, right, postorder);
        root->left = arrayToTree(left, mp[rootVal] - 1, postorder);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz = postorder.size();
        postOrderIndex = sz-1;
        
        for(int i=0; i<sz; i++) {
            mp[inorder[i]] = i;
        }
        
        return arrayToTree(0, sz-1, postorder);
    }
};