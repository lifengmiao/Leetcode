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
        string out;
        if(!root) return out;
        dfs(root, out);
        return out;
    }
    void dfs(TreeNode* node, string& out) {
        if(node) {
            out += to_string(node->val)+" ";
            dfs(node->left, out);
            dfs(node->right, out);
        }
        else
            out += "# ";

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        istringstream in(data);
        return dfs2(in);
    }
    
    TreeNode* dfs2(istringstream &in) {
        string val;
        in >> val;
        if(val=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = dfs2(in);
        root->right = dfs2(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
