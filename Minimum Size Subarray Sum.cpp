class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int minD = INT_MAX;
        int left = 0, right = 0;
        int curSum = 0;
        while(left<=right && right<n) {
            curSum += nums[right];
            if(curSum<s)
                right++;
            else {
                while(left<=right && curSum>=s) {
                    curSum -= nums[left];
                    left++;
                }
                minD = min(minD, right-left+2);
                right++;
            }
        }
        return minD==INT_MAX?0:minD;
    }
};
