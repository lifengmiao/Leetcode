/*
这道题让我们在一系列非重叠的区间中插入一个新的区间，可能还需要和原有的区间合并，
那么我们需要对给区间集一个一个的遍历比较，那么会有两种情况，重叠或是不重叠，不重叠的情况最好，
直接将新区间插入到对应的位置即可，重叠的情况比较复杂，有时候会有多个重叠，
我们需要更新新区间的范围以便包含所有重叠，之后将新区间加入结果res，最后将后面的区间再加入结果res即可。
具体思路是，我们用一个变量cur来遍历区间，如果当前cur区间的结束位置小于要插入的区间的起始位置的话，
说明没有重叠，则将cur区间加入结果res中，然后cur自增1。直到有cur越界或有重叠while循环退出，
然后再用一个while循环处理所有重叠的区间，每次用取两个区间起始位置的较小值，和结束位置的较大值来更新要插入的区间，
然后cur自增1。直到cur越界或者没有重叠时while循环退出。之后将更新好的新区间加入结果res，然后将cur之后的区间再加入结果res中即可，
参见代码如下：
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur].end < newInterval.start) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
