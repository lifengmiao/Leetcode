/*
这道题给了我们一个数组nums和一个数字k，问我们该数字能不能分成k个非空子集合，使得每个子集合的和相同。给了k的范围是[1,16]，而且数组中的数字都是正数。这跟之前那道Partition Equal Subset Sum很类似，但是那道题只让分成两个子集合，所以问题可以转换为是否存在和为整个数组和的一半的子集合，可以用dp来做。但是这道题让求k个和相同的，感觉无法用dp来做，因为就算找出了一个，其余的也需要验证。这道题我们可以用递归来做，首先我们还是求出数组的所有数字之和sum，首先判断sum是否能整除k，不能整除的话直接返回false。然后需要一个visited数组来记录哪些数组已经被选中了，然后调用递归函数，我们的目标是组k个子集合，是的每个子集合之和为target = sum/k。我们还需要变量start，表示从数组的某个位置开始查找，curSum为当前子集合之和，在递归函数中，如果k=1，说明此时只需要组一个子集合，那么当前的就是了，直接返回true。如果curSum等于target了，那么我们再次调用递归，此时传入k-1，start和curSum都重置为0，因为我们当前又找到了一个和为target的子集合，要开始继续找下一个。否则的话就从start开始遍历数组，如果当前数字已经访问过了则直接跳过，否则标记为已访问。然后调用递归函数，k保持不变，因为还在累加当前的子集合，start传入i+1，curSum传入curSum+nums[i]，因为要累加当前的数字，如果递归函数返回true了，则直接返回true。否则就将当前数字重置为未访问的状态继续遍历，参见代码如下：
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%k!=0) return false;
        int target = sum/k;
        vector<bool> visit(nums.size(), false);
        int curSum = 0, start=0;
        return helper(nums, k, target, start, curSum, visit);
        
    }
    
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visit) {
        if(k==1) return true; //the only one return true case; if reach k==1, means the remain element sum is target
        if(curSum==target) return helper(nums, k-1, target, 0, 0, visit); //reset start and curSum
        for(int i=start; i<nums.size(); i++) { //search from 'start', this is for generate one subset with curSUm==target
            if(visit[i]==true) continue; //current element already used to generate previous subset with curSum==target
            visit[i]=true;
            if(helper(nums, k, target, i+1, curSum+nums[i], visit)) 
                return true;
            else
                visit[i]=false; //if not successlly generate one good subset, reset visit[i]
        }
        return false;
        
    }
};
