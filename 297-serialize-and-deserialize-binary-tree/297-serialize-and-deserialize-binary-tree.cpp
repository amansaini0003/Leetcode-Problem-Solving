/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(root == nullptr)
            return str;
       
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            
            if(currNode == nullptr){
                str += "#,";
            } else {
                str += to_string(currNode->val) + ',';
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        cout<< str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            // left
            getline(ss, str, ',');
            if(str == "#"){
                node->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            // right
            getline(ss, str, ',');
            if(str == "#"){
                node->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }   
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));










