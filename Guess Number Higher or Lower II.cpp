/*
此题是之前那道Guess Number Higher or Lower的拓展，难度增加了不少，根据题目中的提示，这道题需要用到Minimax极小化极大算法，
关于这个算法可以参见这篇讲解，并且题目中还说明了要用DP来做，那么我们需要建立一个二维的dp数组，其中dp[i][j]表示从数字i到j之
间猜中任意一个数字最少需要花费的钱数，那么我们需要遍历每一段区间[j, i]，维护一个全局最小值global_min变量，然后遍历该区间中
的每一个数字，计算局部最大值local_max = k + max(dp[j][k - 1], dp[k + 1][i])，这个正好是将该区间在每一个位置都分为两段，
然后取当前位置的花费加上左右两段中较大的花费之和为局部最大值，为啥要取两者之间的较大值呢，因为我们要cover所有的情况，就得取
最坏的情况。然后更新全局最小值，最后在更新dp[j][i]的时候看j和i是否是相邻的，相邻的话赋为i，否则赋为global_min。这里为啥又
要取较小值呢，因为dp数组是求的[j, i]范围中的最低cost，比如只有两个数字1和2，那么肯定是猜1的cost低，是不有点晕，没关系，博
主继续来绕你。我们想，如果只有一个数字，那么我们不用猜，cost为0。如果有两个数字，比如1和2，我们猜1，即使不对，我们cost也比
猜2要低。如果有三个数字1，2，3，那么我们就先猜2，根据对方的反馈，就可以确定正确的数字，所以我们的cost最低为2。如果有四个数
字1，2，3，4，那么情况就有点复杂了，那么我们的策略是用k来遍历所有的数字，然后再根据k分成的左右两个区间，取其中的较大cost加上k。

当k为1时，左区间为空，所以cost为0，而右区间2，3，4，根据之前的分析应该取3，所以整个cost就是1+3=4。

当k为2时，左区间为1，cost为0，右区间为3，4，cost为3，整个cost就是2+3=5。

当k为3时，左区间为1，2，cost为1，右区间为4，cost为0，整个cost就是3+1=4。

当k为4时，左区间1，2，3，cost为2，右区间为空，cost为0，整个cost就是4+2=6。

综上k的所有情况，此时我们应该取整体cost最小的，即4，为最后的答案，这就是极小化极大算法，参见代码如下：
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[j][i] is min cost to guess any numbers in [j,i]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {
                int global_min = INT_MAX;
                for (int k = j + 1; k < i; ++k) {
                    int local_max = k + max(dp[j][k - 1], dp[k + 1][i]); //对于固定k, 要不要猜的数字在左边(dp[j][k - 1])
                                                                         //要不在右边(dp[k+1][i])，所以不需要左右相加
                    global_min = min(global_min, local_max);
                }
                dp[j][i] = j + 1 == i ? j : global_min;
            }
        }
        return dp[1][n];
    }
};
