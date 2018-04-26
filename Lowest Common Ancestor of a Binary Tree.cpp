/*
递归寻找两个待查询的节点p和q，当找到后，返回他们的TreeNode给其父节点。
如果这个父节点的左右子树分别包括这两个节点，那么这个父节点必然是所求的解，返回该父节点。
否则，继续向上层（爷爷节点）返回包含p或者q的TreeNode，注意不是返回父节点，而是返回搜索到的p或者q节点。
如果该子树没有包含p或者q节点，返回NULL。
*/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        else if(!left)
            return right;
        else 
            return left;
    }
};
