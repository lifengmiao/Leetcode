/*
这道题只有 DP 的一个性质： optimal substructure，即用 subproblem (subtree) 的最优解可以构造出全局最优解。optimal substructure性质在 Tree 类问题中非常常见，因此遇到一个问题的时候，要注意按照其性质属性仔细辨别正确解法。
在 Tree 上做递归的时候返回顺序已然是 bottom-up，相对于每一个节点，并没有重复计算，也没有 overlap subproblems，因此这只是一个正常的递归搜索问题，而不需要依赖 DP 进行优化。
dfs 时间复杂度已经是 O(n) , n = # of nodes
*/

class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right)
            return root->val;
        int leftLv1 = 0, rightLv1 = 0;
        int subleftLv2 = 0, subrightLv2 = 0;
        if(root->left) {
            leftLv1 = rob(root->left);
            subleftLv2 = rob(root->left->left)+rob(root->left->right);
        }
        if(root->right) {
            rightLv1=rob(root->right);
            subrightLv2=rob(root->right->left)+rob(root->right->right);
        }
        return max(root->val+subleftLv2+subrightLv2, leftLv1+rightLv1);
        
    }
};
