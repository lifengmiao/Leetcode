/*
扩展
http://www.1point3acres.com/bbs/thread-146255-1-1.html
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==0) return;
        if(nums.size()==1) return;
        bool findBigger = true;
        for(int i=1; i<nums.size(); i++) {
            if(findBigger==true) {
               if (nums[i]<nums[i-1])
                    swap(nums, i, i-1);
            }
            else {
                if(nums[i]>nums[i-1])
                    swap(nums, i, i-1);
            }
            findBigger = !findBigger;
        }
        return;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }
};

http://www.1point3acres.com/bbs/thread-146255-1-1.html
