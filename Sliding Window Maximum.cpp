
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        //queue中为 [当前window中最大元素的位置，在当前window中最大元素位置之后次大元素的位置，。。。]
        deque<int> q; //存的是元素的indx，不是元素本身，只存window中需要存的元素的indx
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) //超出window，remove one element
                q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) //小于当前元素的都删除， 这样做其实还可以保证dq中的元素是按从大到小顺序排列的
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
