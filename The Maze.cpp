/*
这道题让我们遍历迷宫，但是与以往不同的是，这次迷宫是有一个滚动的小球，这样就不是每次只走一步了，
而是朝某一个方向一直滚，直到遇到墙或者边缘才停下来，我记得貌似之前在手机上玩过类似的游戏。
那么其实还是要用DFS或者BFS来解，只不过需要做一些修改。先来看DFS的解法，我们用DFS的同时最好能用上优化，
即记录中间的结果，这样可以避免重复运算，提高效率。我们用二维数组dp来保存中间结果，
然后用maze数组本身通过将0改为-1来记录某个点是否被访问过，这道题的难点是在于处理一直滚的情况，其实也不难，
只要我们有了方向，只要一直在那个方向上往前走，每次判读是否越界了或者是否遇到墙了即可，然后对于新位置继续调用递归函数，
参见代码如下：
*/
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        int n =maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n,false));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(maze, start, destination, visit,dp);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, vector<vector<bool>>& visit, vector<vector<int>>& dp) {
        if(visit[start[0]][start[1]]==true) return false;
        if(start[0]==destination[0] && start[1]==destination[1]) return true;
        visit[start[0]][start[1]]=true;
        if(dp[start[0]][start[1]]!=-1) return dp[start[0]][start[1]];
        bool rst = false;
        int r = start[1]+1, l = start[1]-1, u=start[0]-1, d=start[0]+1;
        int m = maze.size(), n = maze[0].size();
        while(u>=0 && maze[u][start[1]]!=1) u--;
        if(dfs(maze, vector<int>{u+1,start[1]}, destination, visit, dp)) rst = true;
        while(d<m && maze[d][start[1]]!=1) d++;
        if(dfs(maze, vector<int>{d-1,start[1]}, destination, visit, dp)) rst = true;
        while(l>=0 && maze[start[0]][l]!=1) l--;
        if(dfs(maze, vector<int>{start[0],l+1}, destination, visit, dp)) rst = true;
        while(r<n && maze[start[0]][r]!=1) r++;
        if(dfs(maze, vector<int>{start[0],r-1}, destination, visit, dp)) rst = true;
        dp[start[0]][start[1]] = rst;
        return rst;
    }
};
