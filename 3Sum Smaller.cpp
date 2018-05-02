class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=0; i<n;i++) {
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>=target) 
                    right--;
                else {
                    cnt += (right-left); //sum < target 时，i 和 left 不动，介于 left 和 right (包括 right) 之间的所有元素 sum 也一定小于 target 
                    left++;
                }
            }
        }
        return cnt;
    }
};
