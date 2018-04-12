/*
和 Edit distance 非常像，前者两个string, convert S1 to S2
问题的 optimal substructure 即为
dp[i][j] = substring(i,j) 范围内，构造 palindrome 的最小编辑次数
如果 s[i] == s[j]
dp[i][j] = dp[i + 1][j - 1] (不需要操作)
同时考虑 i , j 相邻的情况
如果 s[i] != s[j]，那么我们可以经 add 操作构造出当前的 s(i, j)
s(i + 1, j) + ADD 在右边加s[i]
s(i, j - 1) + ADD 在左边加s[j]
注意这题不支持 replace，如果支持的话，dp[i][j] 还要看一个新状态，dp[i + 1][j - 1]
*/
/*
注意下面的解法颠倒了上面介绍里的i,j
*/
class Solution {
public:
    int minInsertion(string str) {
        int n = str.length();
        if(n<=1) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=1; i<n; i++)
            for(int j=i; j>=0; j--)
                if(j==i)
                    dp[i][j] = dp[j][i] = 0;
                else {
                    if(str[i]==str[j])
                        dp[i][j]=dp[j][i]=(j+1==i)?0:dp[j+1][i-1];
                    else
                        dp[i][j]=dp[j][i]=min(dp[j+1][i],dp[j][i-1])+1;
                        //如果支持replace
                        //dp[i][j]=dp[j][i]=min(dp[j+1][i],dp[j][i-1],dp[j+1][i-1])+1;
                }
        return dp[0][n-1];
    }
};
