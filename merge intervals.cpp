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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> out;
        if (intervals.size()==0) return out;
        if (intervals.size()==1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        Interval preInv = intervals[0];
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start > preInv.end)  {
                out.push_back(preInv);
                preInv = intervals[i];
            }
            else {
                preInv.start = min(intervals[i].start, preInv.start);
                preInv.end = max(intervals[i].end, preInv.end);
            }
        }
        out.push_back(preInv);
        return out;
    }
};
