class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int rst=0;
        longestPath(root, rst);
        return rst;
    }
    //return the longest increase and decrease path including current node
    vector<int> longestPath(TreeNode* root, int& rst) {
        if(!root) return vector<int>{0,0};
        int inc = 1, dec = 1;
        if(root->left) {
            vector<int> left = longestPath(root->left, rst);
            if(root->val-1 ==root->left->val) 
                inc = left[0]+1;
            if(root->val+1 == root->left->val)
                dec = left[1]+1;
        }
        if(root->right) {
            vector<int> right = longestPath(root->right, rst);
            if(root->val-1 ==root->right->val) 
                inc = max(inc, right[0]+1);
            if(root->val+1 == root->right->val)
                dec = max(dec, right[1]+1);
        }
        rst = max(rst, inc+dec-1);
        return vector<int> {inc, dec};
    }
};
