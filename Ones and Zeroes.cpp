//背包问题
//循环顺序有变，之前对于dp[i][j]遍历所有选择，本题是对于一个特定选择 strs[i]， 更新所有dp[i][j]
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str) (c == '0') ? ++zeros : ++ones;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


//self Wrong
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<bool> visit(strs.size(), false);
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
        dfs(0, strs, m, n, visit, 0, res, cnt0, cnt1);
        return res;
    }
    
    void dfs(int start, vector<string>& strs, int m, int n, vector<bool>& visit, int cnt, int& res, vector<int>& cnt0, vector<int>& cnt1) {
        if(m==0 && n==0) {
            res = max(res, cnt);
            return;
        }
        if(m<0 || n<0) {
            res = max(res, cnt-1);
            return;
        }
        for(int i=start; i<strs.size();i++) {
            if(visit[i]==true) continue;
            visit[i]=true;
            // if(m>=cnt0[i] && n>=cnt1[i])
                dfs(i+1, strs, m-cnt0[i], n-cnt1[i], visit, cnt+1, res, cnt0, cnt1);
            visit[i]=false;
        }
    }
};
