/*
p[i] color on ith fence
两种情况：
1. p[i]!=p[i-1] 颜色不同，当前fence可以有k-1种选择，所以 （k-1）*dp[i-1]
2. p[i]==p[i-1] 颜色相同，当前fence决定于前一fence所有选择中的一部分，即前一fence和前前一fence颜色不同的那部分，这部分的数量为 (k-1)*dp[i-2]
颜色相同，当前fence其实只有一种选择，所以应该是 dp[i]=1*dp_hat[i-1],但是这里的dp_hat[i-1] 要有条件，即p[i-1]!=p[i-2], 所以dp_hat[i-1]=(k-1)*dp[i-2]
*/

class Solution {
public:
    int numWays(int n, int k) {
        if (n==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        int dp[3];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        for (int i=3; i<=n; i++) {
            dp[i%3] = (k-1)*(dp[(i-1)%3]+dp[(i-2)%3]);
        }
        return dp[n%3];
            
    }
};
