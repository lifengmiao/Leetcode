/*
如果上面的解法的坐标转换不好想的话，我们也可以考虑用DP解法来做，我们建立一个三维dp数组，其中dp[i][j][k]表示从开头
遍历到数字nums[i][j]为止，第k种情况的连续1的个数，k的值为0，1，2，3，分别对应水平，竖直，对角线和逆对角线这四种情况。
之后就是更新dp数组的过程了，如果如果数字为0的情况直接跳过，然后水平方向就加上前一个的dp值，竖直方向加上上面一个数字
的dp值，对角线方向就加上右上方数字的dp值，逆对角线就加上左上方数字的dp值，然后每个值都用来更新结果res，参见代码如下：
*/
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) dp[i][j][k] = 1; //Initial 4 direction with 1, no matter if any corresponding neighber exist
                if (j > 0) dp[i][j][0] += dp[i][j - 1][0]; // horizonal
                if (i > 0) dp[i][j][1] += dp[i - 1][j][1]; // vertical
                if (i > 0 && j < n - 1) dp[i][j][2] += dp[i - 1][j + 1][2]; // diagonal
                if (i > 0 && j > 0) dp[i][j][3] += dp[i - 1][j - 1][3]; // anti-diagonal
                res = max(res, max(dp[i][j][0], dp[i][j][1]));
                res = max(res, max(dp[i][j][2], dp[i][j][3]));
            }
        }
        return res;
    }
};
