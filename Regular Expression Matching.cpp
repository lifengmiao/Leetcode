//http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
/*
关键在于如何处理这个'*'号。

状态：和Mininum Edit Distance这类题目一样。
dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。

递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]

而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
dp[i][j] = dp[i][j-2]

2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
dp[i][j] = dp[i][j-1]

3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] }
dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-1]==p[j-2])
其中 dp[i-1][j] 表示s[0:i-2] 可以match当前p[0:j-1], 然后 pattern多了一个p[j-2], 只要保证当前s[j-1]==p[j-2]即可。如下列子：
s:  abc    -> abcc                ->abccc
p:  abc*   2 preceding element    3 preceding element
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i=0; i<=m; i++)
            for(int j=1;j<=n; j++) {
                if(p[j-1]!='.' && p[j-1]!='*') 
                    dp[i][j] = (i>0 && s[i-1]==p[j-1] && dp[i-1][j-1]);
                else if(p[j-1]=='.')
                    dp[i][j] = (i>0 && dp[i-1][j-1]);
                else if(p[j-1]=='*') {
                    if(dp[i][j-1] || dp[i][j-2])
                        dp[i][j]=true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j])
                        dp[i][j]=true;
                }
                    
            }
        return dp[m][n];
    }
};
