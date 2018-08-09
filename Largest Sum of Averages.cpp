class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> P(n+1,0);
        for(int i=0;i<n;i++) {
            P[i+1]=P[i]+A[i];
        }
        //Let dp(i, k) be the best score partioning A[i:] into at most K parts.
        vector<vector<double>> dp(n,vector<double>(K+1,0)); //k start from 1, no partition, 1 group
        for(int i=0; i<n;i++) {
            for(int k=1; k<=K; k++) //initialize all K, start from 1
                dp[i][k] = (P[n]-P[i])/(n-i); //average A[i:]
        }
        for(int k=2; k<=K; k++) { //start from 2, since k=1 already initialized
            for(int i=0;i<n;i++) {
                for(int j=i+1; j<n; j++) {
                    dp[i][k] = max(dp[i][k], (P[j]-P[i])/(j-i)+dp[j][k-1]);
                }
            }
        }
        return dp[0][K];
    }
};
