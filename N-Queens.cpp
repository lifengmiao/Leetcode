/*
回溯递归，一层一层的向下扫描，需要用到一个pos数组，其中pos[i]表示第i行皇后的位置，
初始化为-1，然后从第0开始递归，每一行都一次遍历各列，判断如果在该位置放置皇后会不
会有冲突，以此类推，当到最后一行的皇后放好后，一种解法就生成了，将其存入结果res中，
然后再还会继续完成搜索所有的情况，
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rst;
        vector<int> pos(n,-1);
        int row=0;
        dfs(row, pos, rst);
        return rst;
    }
    
    void dfs(int row, vector<int>& pos, vector<vector<string>>& rst) {
        int n = pos.size();
        if(row==n) { //depth reach last
            vector<string> tmp(n, string(n, '.'));
            for(int i=0; i<pos.size(); i++) {
                tmp[i][pos[i]] = 'Q';
            }
            rst.push_back(tmp);
            return;
        }
        for(int j=0; j<n; j++) { //options
            if(isValid(pos, row, j)) {
                pos[row] = j;
                dfs(row+1, pos, rst);
                pos[row] = -1; //backtracking
            }
        }
    }
    
    bool isValid(vector<int>& pos, int row, int col) {
        for(int i=0; i<row; i++) {
            if(col == pos[i] || (abs(col-pos[i])==abs(row-i))) //diag
                return false;
        }
        return true;
    }
};
