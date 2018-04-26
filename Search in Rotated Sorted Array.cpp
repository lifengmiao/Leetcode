/*
判断哪边有序使用 nums[mid]<nums[right] 或者 nums[mid]>=nums[left]
因为当mid 和 left指向同一元素，左边是有序的，而右边是无序的，比如
[3,1] target=1

注意，因为没有重复元素存在，不会存在nums[mid]==nums[right]，除非mid==right,而这种情况下 left必然也等于mid，即left==mid==right;
然而mid==left,可能是 mid==left==right-1
如果有重复元素，if (nums[mid]<nums[right]) 右边有序； if（nums[mid]>nums[right]) 左边有序；if(nums[mid]==nums[right]) 无法确定，只能排除nums[right]
比如
3 1 2 3 3 3 3 
3 3 3 3 1 2 3
code 见Search in Rotated Sorted Array II
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
