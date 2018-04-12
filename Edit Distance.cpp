/*
1. 状态：
DP[i+1][j+1]：word1[0:i] -> word2[0:j]的最小edit distance。

2. 通项公式：
考虑word1[0:i] -> word2[0:j]的最后一次edit。无非题目中给出的三种方式：

a) 插入一个字符：word1[0:i] -> word2[0:j-1]，然后在word1[0:i]后插入word2[j]
DP[i+1][j+1] = DP[i+1][j]+1

b) 删除一个字符：word1[0:i-1] -> word2[0:j]，然后删除word1[i]
DP[i+1][j+1] = DP[i][j+1]+1

c) 替换一个字符：word1[0:i-1] -> word2[0:j-1]
word1[i] != word2[j]时，word1[i] -> word2[j]：DP[i+1][j+1] = DP[i][j] + 1
word1[i] == word2[j]时：DP[i+1][j+1] = DP[i][j] 

所以min editor distance应该为：
DP[i+1][j+1] = min(DP[i][j] + k, DP[i+1][j]+1, DP[i][j+1]+1) 
word1[i]==word2[j] -> k = 0, 否则k = 1

3. 计算方向：
replace (i, j)      delete (i, j+1)
insert (i+1, j)    (i+1, j+1)

可见要求DP[i+1][j+1]，必须要知道二维矩阵中左上，上方和下方的3个值。所以当我们确定第0行和第0列的值后，就可以从上到下、从左到右的计算了。

4. 起始、边界值
DP[0][j] = j： word1为空，要转化到word2[0:j-1]，需要添加i个字符。
DP[i][0] = i： word2为空，要从word1转化到空字符串，需要删除i个字符。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int j=1; j<=n; j++)
            dp[0][j] = j;
        for(int i=1; i<=m; i++) {
            dp[i][0] = i;
            for(int j=1; j<=n; j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j]+1, dp[i][j-1]+1));
                else
                    dp[i][j]=min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        return dp[m][n];
    }
};
