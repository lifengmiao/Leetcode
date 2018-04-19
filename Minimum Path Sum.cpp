class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=m?grid[0].size():0;
        if(m==0) return 0;
        vector<int> dp(n,INT_MAX); //no need to add 1
        dp[0]=0;
        for(int i=0;i<m;i++) {
            dp[0] = dp[0]+grid[i][0]; //Initialize first column
            for(int j=1;j<n;j++) {
                dp[j] = min(dp[j], dp[j-1])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};
