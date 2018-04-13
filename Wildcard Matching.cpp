/*
dp[i][j] 代表 s 的前 i 个字符串能否和 p 的前 j 个字符串成功匹配，以 dp[n][m] 为最终解。

s[i] , p[j] 为 s , p 的第 i / j 个字符，略去 off-by-one 的 index 问题
当 p[j] = 常规字母时；
如果 s[i] == p[j]，当前位置 match;
同时如果之前的字符串 dp[i - 1][j - 1] 也 match ，则 dp[i][j] match;
当 p[j] 为 '?' 时；
当前位置一定 match，只看 dp[i - 1][j - 1] 是否也 match;
当 p[j] 为 '*' 时；
只 match 当前一个字符，看 dp[i - 1][j - 1];
LeetCode 测试了下，其实这行拿掉也是正确的
不 match 任何字符，看 dp[i][j - 1] (忽略 p[j] 的存在)
match 多个字符，看 dp[i - 1][j]
注意这里由于循环结构的关系，其实对于每一个 j ，我们会去考虑 [0 , i-1] 所有的可能性，所以可以用一个状态指代所有前面的 match.
最后要注意一下 dp[0][0], dp[0][i] 的初始化。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int j=1;j<=n;j++) //初始化 for corner case s=""; p="*"
            if(p[j-1]=='*')
                dp[0][j] = true;
            else
                break; //不是'*' 要break, for case s="aab";  p="c*a*b"
        
        for (int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1]==p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j-1]||dp[i][j-1]||dp[i-1][j];
            }
        }
        return dp[m][n];
        
    }
};
