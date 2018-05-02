class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        int n=nums.size();
        if(n<3) return rst;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++) {
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0) {
                    rst.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1]) left++; //remove duplicate
                    while(right>left && nums[right]==nums[right+1]) right--; //remove duplicate
                }
                else if(sum<0)
                    left++;
                else 
                    right--;
            }
            while(i<n-2 && nums[i+1]==nums[i]) i++; //remove duplicate
        }
        return rst;
    }
};
