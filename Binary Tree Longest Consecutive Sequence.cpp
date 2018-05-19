/*
错误解法，因为中间可能有断，比如， 1->2->1->5->6->7 结果应该是3，但是下面解法结果是5，累加了 1->2 和 5->6->7
*/
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = 0, right=0;
        if(root->left) {
            if(root->val - root->left->val==-1)
                left = longestConsecutive(root->left)+1;
            else
                left = longestConsecutive(root->left);
        }
        if(root->right) {
            if(root->val - root->right->val==-1)
                right = longestConsecutive(root->right)+1;
            else
                right = longestConsecutive(root->right);
        }
        return max(left, right);
        
    } 
};

/*
正确解法
*/
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int rst = 0;
        dfs(root, 1, rst);
        return rst;
    }
    
    void dfs(TreeNode* root, int curLen, int& rst) {
        rst = max(rst, curLen);
        if(root->left) {
            if(root->val+1 == root->left->val)
                dfs(root->left, curLen+1, rst);
            else
                dfs(root->left, 1, rst);
            
        }
        if(root->right) {
            if(root->val+1 == root->right->val)
                dfs(root->right, curLen+1, rst);
            else
                dfs(root->right, 1, rst);
            
        }
    }
};
