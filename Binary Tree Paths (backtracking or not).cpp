/*
Use copy of string, no need backtracking
*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        string list;
        dfs(root, list, out);
        return out;
    }
    
    void dfs(TreeNode* node, string list, vector<string>& out) {
        if(!node)
            return;
        list += "->"+to_string(node->val);
        if(!node->left && !node->right) {
            out.push_back(list.substr(2));
            return;
        }
        dfs(node->left, list, out);
        dfs(node->right, list, out);
    }
};

/*
Pass reference, need backtracking
*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        string list;
        dfs(root, list, out);
        return out;
    }
    
    void dfs(TreeNode* node, string& list, vector<string>& out) {
        if(!node)
            return;
        int len = list.length();
        list += "->"+to_string(node->val);
        if(!node->left && !node->right) {
            out.push_back(list.substr(2));
            list = list.substr(0,len);
            return;
        }
        dfs(node->left, list, out);
        dfs(node->right, list, out);
        list = list.substr(0,len);
    }
};
