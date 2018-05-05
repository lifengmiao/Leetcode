class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n<=1) return 0;
        int maxL = INT_MIN;
        vector<int> dp(n, 0);
        for(int i=1; i<n; i++) {
            if(s[i]==')') {
                int len = dp[i-1];
                int leftIndx = i-len-1;
                if(leftIndx>=0 && s[leftIndx]=='(') {
                    dp[i] = dp[i-1]+2;
                    cout<<i<<' '<<dp[i]<<endl;
                    if(leftIndx-1>=0)
                        dp[i] += dp[leftIndx-1];
                }
                else
                    dp[i]=0;
            }
            maxL = max(maxL, dp[i]);
        }
        return maxL;
    }
};
