/*
也是 Hard 题，长得还和 Wildcard Matching 特别像。
最大的不同是，在这里 '*' 号是和其前一个字符有联系的，和其前一个字符一起，代表着“多个或0个星号前面的字符”。 这里我们需要假设 p 不会以星号开始，也不会有连续多个星号出现，不然现有题意描述是无法解决这些问题的。
遇到常规字母和 '.' 的处理和上一题没有任何区别；
遇到 p[j] 为星号时：
如果 p[j - 1] 是 '.', 那么这个星号
dp[i - 1][j] 以当前星号匹配一个或多个多个字符；
dp[i][j - 1] 只让 p[j - 1] 匹配，当前星号不匹配字符；
dp[i][j - 2] 同下。
否则，星号位置能否匹配取决于 dp[i][j - 2]，即让(p[j - 1] + 当前星号)都不匹配任何字符。
以这两道题看，dp[i - 1][j] 都代表着 “以 p 当前 * 字符，匹配 s 的[1,n]长度字符”
这题dp[0][i]初始化和 Wildcard 不太一样，因为会有 c*a*b 这种情况，多个星号跳着出现，不要立刻 break 掉，而要扫到底，dp[0][i] 要看 dp[0][i - 2];
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int j = 2; j<=n; j++) //start from 2, since first elment can't be *
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-2]; //for case: s="" p=c*a* true
        
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] || ((p[j-2]==s[i-1]||p[j-2]=='.') &&dp[i-1][j]);
            }
        return dp[m][n];
    }
};

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
