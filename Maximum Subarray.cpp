class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int myMax = INT_MIN;
        int cumulate = 0;
        for (int i=0; i<nums.size(); i++) {
            if(cumulate<0) {
                cumulate = nums[i];
                myMax = max(myMax, cumulate);
            }
            else {
                cumulate += nums[i];
                myMax = max(myMax, cumulate);
            }
                
                
        }
        return myMax;
    }
};
