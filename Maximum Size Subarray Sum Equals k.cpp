/*
prefix sum array + two sum，利用前缀和数组实现快速区间和查询，同时 two sum 的方法快速地位 index.
这种 prefix sum 的下标要格外小心，很容易标错。。target value 差也是，写之前多手动过几个 case 保平安。
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        int prefixSum = 0;
        int maxL = INT_MIN;
        map<int, int> mMap;
        mMap[0] = 0; //put 0 as initial sum
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];
            if(mMap.find(prefixSum-k)!=mMap.end()) {
                maxL = max(maxL, i-mMap[prefixSum-k]+1);
            }
            if(mMap.find(prefixSum)==mMap.end()) //之前如果有不需要更新，因为是求最长距离，如果求最短距离，更新
                mMap[prefixSum]=i+1; //since initial has take one place, insert i+1
                
        }
        return maxL==INT_MIN?0:maxL;
    }
};
