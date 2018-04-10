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
// BFS
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        queue<TreeNode*> q;
        if(!root) return out;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                out += to_string(node->val)+' ';
                q.push(node->left);
                q.push(node->right);
            }
            else
                out += "# ";
        }
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        istringstream in(data);
        string val;
        in>>val;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty())  {
            TreeNode* curr = q.front();
            q.pop();
            if(!(in>>val)) break;
            if(val!="#") {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);   
            }
            if(!(in>>val)) break;
            if(val!="#"){
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }
        return root;
    }
};
