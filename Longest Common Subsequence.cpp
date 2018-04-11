/*
dp[i][j] is the LCS of A[0:i-1] and B[0:j-1]
*/

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        if(m==0 || n==0) return 0;
        int dp[m+1][n+1] = {0};
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                if(A[i-1]==B[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;    
                }
                else {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        return dp[m][n];
    }
};
