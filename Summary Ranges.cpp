class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> rst;
        if(n==0) return rst;
        int l = 0, r = 1;
        while(l<n && r<=n) {
            while(r<n && nums[r]-nums[r-1]==1) {
                r++;
            }
            if(r-l==1)
                rst.push_back(to_string(nums[l]));
            else
                rst.push_back(to_string(nums[l])+"->"+to_string(nums[r-1]));
            l = r;
            r++;
        }
        return rst;
    }
};
