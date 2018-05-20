class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int rst = 0;
        dfs(root, rst);
        return rst;
    }
    int dfs(TreeNode* root, int& rst) { //包含当前节点的最长单向路径
        if(!root) return 0;
        int left = dfs(root->left, rst); //包含左节点最长单向路径
        int right = dfs(root->right, rst); //包含右节点最长单向路径
        if(root->left && root->left->val==root->val) //相同 +1
            left++; 
        else //不同 重置
            left = 0;
        if(root->right && root->right->val==root->val)
            right++;
        else right=0;
        
        rst = max(rst,left+right); //global maximun vs curr maximun
        return max(left, right); //单向 所以取最大值
    }
};
