class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res=0;
        dfs(nums, S, 0, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int sum, int start, int& res) {
        if(start>=nums.size()) {
            if(sum==0) {
                res ++;
            }
            return;
        }
        //only two choice, note the difference with combination
            dfs(nums, sum-nums[start], start+1, res);
            dfs(nums, sum+nums[start], start+1, res);
            
    }
};

//memorize with dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, S, 0, dp);
    }
    int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) {
        if (start == nums.size()) return sum == 0;
        if (dp[start].count(sum)) return dp[start][sum];
        int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
        int cnt2 = helper(nums, sum + nums[start], start + 1, dp);
        return dp[start][sum] = cnt1 + cnt2;
    }
};
