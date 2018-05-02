class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, k, 0, nums.size()-1);
    }
    
    int partition(vector<int>& nums, int k, int start, int end) {
        int pivot = nums[start];
        int left = start+1;
        int right = end;
        while(left<=right) {
            while(left<=right && nums[left]>=pivot) left++;
            while(right>=left && nums[right]<=pivot) right--;
            if(left<right) swap(nums, left, right); //注意仅当left<right时才交换，如果left>right不需要交换
        }
        swap(nums, start, right);//把pivot放到正确位置，pivot左边都是大于pivot的值，pivot右边都是小于pivot的值
        if(k==right+1) {
            return nums[right];
        }
        if(k>right+1)
            return partition(nums, k, right+1, end);
        else
            return partition(nums, k, start, right-1);
    }
    
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};
