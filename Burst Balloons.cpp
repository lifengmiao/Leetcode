/*
这题和石子归并很像，更像 Matrix Chain Multiplication. 都是区间类 DP，而且原数组会随着操作逐渐减小，动态变化。
然而就算是动态变化的数组，变化的也并不是状态，而只是子状态的范围，记忆化搜索中的 (start, end).
所以这题的难点在于，如何在动态变化的数组中，依然正确定义并计算 subproblem.
问题一：边界气球
考虑到计算方式为相邻气球乘积，可以两边放上 1 来做 padding，不会影响最后结果的正确性。
问题二：子问题返回后，如何处理相邻气球？
在stone game中，最后融合两个区间要靠区间和；
在busrt balloon中，两个区间返回时已经都被爆掉了，融合区间靠的是两个区间最外面相邻的气球。（因此 padding 才很重要）
正如 Matrix Chain Multiplication 中，左右区间相乘结束返回时，最后融合那步的 cost = A(start).rows * A(k).cols * A(end).cols
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> padNums(nums);
        padNums.insert(padNums.begin(),1);
        padNums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        return memorizedSearch(1,n,padNums,dp);
    }
    
    int memorizedSearch(int start, int end, vector<int>& padNums, vector<vector<int>>& dp) {
        if(dp[start][end]!=0) {return dp[start][end];}
        int maxC = 0;
        for(int i=start;i<=end;i++) {
            int cur = padNums[start-1]*padNums[i]*padNums[end+1];
            int left = memorizedSearch(start,i-1,padNums,dp);
            int right = memorizedSearch(i+1,end,padNums,dp);
            maxC = max(maxC, cur+left+right);
        }
        dp[start][end]=maxC;
        return maxC;
    }
};
