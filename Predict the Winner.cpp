class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum1=0, sum2 = 0;
        int i=0, j=nums.size()-1;
        int player = 1;
        return dfs(nums, sum1, sum2, i, j, player); //dfs return if current player can win
    }
    
    bool dfs(vector<int>& nums, int sum1, int sum2, int i, int j, int player) {
        if(i==j) {
            if(player==1)
                return sum1+nums[i]>=sum2; //sum1 is fixed assigned to player1
            else if(player==2)
                return sum2+nums[i]>sum1;  //sum2 is fixed assigned to player2
        }
        if(player==1)
            return !dfs(nums, sum1+nums[i], sum2, i+1, j, 2) || !dfs(nums, sum1+nums[j], sum2, i, j-1, 2);
        if(player==2)
            return !dfs(nums, sum1, sum2+nums[i], i+1, j, 1) || !dfs(nums, sum1, sum2+nums[j], i, j-1, 1);
    }
};
