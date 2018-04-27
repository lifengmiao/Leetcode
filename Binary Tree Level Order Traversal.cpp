/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (!root) return out;
        queue<TreeNode*> mQ;
        mQ.push(root);
        while(!mQ.empty()) {
            int size = mQ.size(); //need to save the size before iteration, otherwise, mQ.size() will change after each iteration
            vector<int> list;
            for(int i=0; i < size; i++) { //can't use mQ.size() here
                TreeNode* node = mQ.front();
                list.push_back(node->val);
                if(node->left) mQ.push(node->left);
                if(node->right) mQ.push(node->right);
                mQ.pop();
            }
            out.push_back(list);
        }
        return out;
    }
};
