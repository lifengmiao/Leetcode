//背包问题
//循环顺序有变，之前对于dp[i][j]遍历所有选择，本题是对于一个特定选择 strs[i]， 更新所有dp[i][j]
//注意更新顺序是从后向前，避免多次使用同一元素！！！！如果从前向后（一般DP都是从前向后），会多次使用同一元素
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str) (c == '0') ? ++zeros : ++ones;
            for (int i = m; i >= zeros; --i) {//更新顺序从后向前
                for (int j = n; j >= ones; --j) {//更新顺序从后向前
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


//self TLE
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> cnt0(strs.size(),0);
        vector<int> cnt1(strs.size(),0);
        for(int i=0; i<strs.size(); i++) {
            for(int j=0; j<strs[i].length(); j++) {
                if(strs[i][j]=='0')
                    cnt0[i]++;
                else if(strs[i][j]=='1')
                    cnt1[i]++;
            }
        }
        int res = 0;
        res = dfs(0, strs, m, n, cnt0, cnt1);
        return res;
    }
    
    int dfs(int start, vector<string>& strs, int m, int n, vector<int>& cnt0, vector<int>& cnt1) {
        if((m==0 && n==0) || start==strs.size()) {
            return 0;
        }
        int use =0;
        if (m-cnt0[start]>=0 && n-cnt1[start]>=0)
            use = dfs(start+1, strs, m-cnt0[start], n-cnt1[start], cnt0, cnt1)+1;
        int notuse = dfs(start+1, strs, m, n, cnt0, cnt1);
        return max(use, notuse);
    }
};
