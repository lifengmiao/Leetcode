/*
我在论坛里看到了史蒂芬大神提出的另一种解法，感觉挺巧妙，就搬了过来。这种解法比较省空间，
写法也比较简洁，需要一个rowCnt变量，用来记录到下一个墙之前的敌人个数。还需要一个数组colCnt，
其中colCnt[j]表示第j列到下一个墙之前的敌人个数。算法思路是遍历整个数组grid，
对于一个位置grid[i][j]，对于水平方向，如果当前位置是开头一个或者前面一个是墙壁，
我们开始从当前位置往后遍历，遍历到末尾或者墙的位置停止，计算敌人个数。对于竖直方向也是同样，
如果当前位置是开头一个或者上面一个是墙壁，我们开始从当前位置向下遍历，遍历到末尾或者墙的位置停止，
计算敌人个数。可能会有人有疑问，为啥rowCnt就可以用一个变量，而colCnt就需要用一个数组呢，
为啥colCnt不能也用一个变量呢？原因是由我们的遍历顺序决定的，我们是逐行遍历的，
在每行的开头就统计了该行的敌人总数，所以再该行遍历没必要用数组，但是每次移动时就会换到不同的列，
我们总不能没换个列就重新统计一遍吧，所以就在第一行时一起统计了存到数组中供后来使用。有了水平方向
和竖直方向敌人的个数，那么如果当前位置是0，表示可以放炸弹，我们更新结果res即可，
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0, rowCnt, colCnt[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowCnt = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                        rowCnt += grid[i][k] == 'E';
                    }
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colCnt[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                        colCnt[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') {
                    res = max(res, rowCnt + colCnt[j]);
                }
            }
        }
        return res;
    }
};
