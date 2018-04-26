/*
判断哪边有序使用 nums[mid]<nums[right] 或者 nums[mid]>=nums[left]
因为当mid 和 left指向同一元素，左边是有序的，而右边是无序的，比如
[3,1] target=1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int left = 0, right = nums.size()-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<nums[right]) {
                if(target>nums[mid] && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else {
                if(target>=nums[left] && target<nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return -1;
    }
};
