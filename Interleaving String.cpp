/*
其中dp[i][j] 表示的是 s2 的前 i 个字符和 s1 的前 j 个字符是否匹配 s3 的前 i+j 个字符
dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
两种情况：1.s3 当前字母等于s1当前字母 dp[i][j] = dp[i - 1][j] 
         2.s3 当前字母等于s2当前字母 dp[i][j] = dp[i][j-1] 
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(s3.length()!=m+n) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1; i<=m; i++) //initialization for case s2=''
            if(s3[i-1]==s1[i-1])
                dp[i][0] = dp[i-1][0];
        for(int i=1; i<=n; i++) ////initialization for case s1=''
            if(s3[i-1]==s2[i-1])
                dp[0][i] = dp[0][i-1];
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = (s3[i-1+j]==s1[i-1]&&dp[i-1][j]) || (s3[i-1+j]==s2[j-1]&&dp[i][j-1]) ;
        return dp[m][n];
    }
}; 
