/*
http://www.lintcode.com/en/problem/backpack/
dp[i][sum] = 前 i 个元素里我们能不能凑出来 sum.
dp[i][sum] 要么取决于 dp[i - 1][sum] (不取当前元素)
要么取决于 dp[i - 1][sum - nums[i]] (取当前元素)
其中每一行 i 都只考虑前一行 i - 1 的值。
*/

public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    public int backPack(int m, int[] A) {
        // write your code here
        // dp[i][j] for the first i elements, can we make sum of j
        boolean[][] dp = new boolean[A.length + 1][m + 1];

        for(int i = 0; i <= A.length; i++) dp[i][0] = true;

        for(int i = 1; i <= A.length; i++){
            for(int j = 1; j <= m; j++){
                if(j - A[i - 1] >= 0) 
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - A[i - 1]]);
                else dp[i][j] = dp[i - 1][j];
            }
        }

        for(int i = m; i >= 0; i--) 
            if(dp[A.length][i]) return i;

        return -1;
    }
}
