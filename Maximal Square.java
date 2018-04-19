/*
dp[i][j] 为包含matrix[i][j]这点的square的最大面积, 所以是 local max
所以还需要一个变量max存储global max
*/

public class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix == null || matrix.length == 0) return 0;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int max = 0; //global max

        int[][] dp = new int[2][cols]; //local max

        for(int i = 0; i < cols; i++){
            dp[0][i] = matrix[0][i] - '0'; //initialize of first row
            max = Math.max(dp[0][i], max);
        }

        for(int i = 1; i < rows; i++){
            dp[i % 2][0] = matrix[i][0] - '0'; //initialize of first column
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == '0'){
                    dp[i % 2][j] = 0;
                } else {
                    dp[i % 2][j] = Math.min(dp[i % 2][j - 1],
                                   Math.min(dp[(i - 1) % 2][j], 
                                            dp[(i - 1) % 2][j - 1])) + 1;
                }
                max = Math.max(dp[i % 2][j], max);
            }
        }

        return max * max;
    }
}
