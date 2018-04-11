/*
localMax[i][j] 表示第i天，最多进行了j次交易，最后一次交易在第i天卖出，所能获得最大利润
globalMax[i][j] 表示第i天，最多进行了j次交易，而且第i天可操作可不操作，所能获得最大利润
递推公式：
local[i][j] = max(global[i - 1][j - 1]，local[i - 1][j]）+ diff
global[i][j] = max(local[i][j], global[i - 1][j]）
其中局部最优值是比较
1.前一天并少交易一次的全局最优（因为少交易一次，最后一次交易可在最后一天补上），
2.前一天的局部最优，（前一天卖出，可以转为今天卖出）
3. 最后加上差值

全局最优比较局部最优和前一天的全局最优。
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0 || n==1) return 0;
        if(k>=n/2) {
            int profit = 0;
            for(int i=1; i<n; i++) {
                profit += max(0, prices[i]-prices[i-1]);
            }
            return profit;
        }
        
        vector<vector<int>> localMax(n, vector<int>(k+1,0));
        vector<vector<int>> globalMax(n, vector<int>(k+1,0));
        for(int i=1; i<n; i++) {
            int profit = prices[i]-prices[i-1];
            for(int j=1; j<=k; j++) {
                localMax[i][j] = max(globalMax[i-1][j-1], localMax[i-1][j])+profit;
                globalMax[i][j] = max(localMax[i][j], globalMax[i-1][j]);
            }
        }
        return globalMax[n-1][k];
    }
};
