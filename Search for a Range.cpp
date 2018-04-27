class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return vector<int>{-1,-1};
        vector<int> out;
        int left = 0;
        int right = n-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid] < target) left=mid+1;
            else if(nums[mid]>target) right = mid-1;
            else {
                while(nums[left]!=target) {
                    left++;
                }
                out.push_back(left);
                while(nums[right]!=target) {
                    right--;
                }
                out.push_back(right);
                return out;
            }
        }
        out.push_back(-1);
        out.push_back(-1);
        return out;
    }
};
