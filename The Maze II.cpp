/*
self code 
not work!!!!!!!
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m =  maze.size(), n= maze[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        return dfs(maze, 0, start, destination, visit, dp);
    }
    
    int dfs(vector<vector<int>>& maze, int cnt, vector<int> start, vector<int>& destination, vector<vector<bool>>& visit, vector<vector<int>>& dp) {
        cout<<start[0]<<"  "<<start[1]<<endl;
        if(start[0]==destination[0]&&start[1]==destination[1]) {
            return cnt;
        }   
        if(visit[start[0]][start[1]]) return INT_MAX;
        if(dp[start[0]][start[1]]!=INT_MAX) {
            return dp[start[0]][start[1]];
        }
        visit[start[0]][start[1]] = true;
        int r = start[1]+1, l = start[1]-1, u=start[0]-1, d=start[0]+1;
        int m = maze.size(), n = maze[0].size();
        int up=INT_MAX, down=INT_MAX, right=INT_MAX, left=INT_MAX;
        if(u>=0) {
            int cnt_up = cnt;
            while(u>=0 && maze[u][start[1]]!=1) {u--; cnt_up++;}
            up =dfs(maze, cnt_up-1, vector<int>{u+1,start[1]}, destination, visit, dp);
        }
        if(d<m) {
        int cnt_down = cnt;
        while(d<m && maze[d][start[1]]!=1) {
            d++; 
            cnt_down++;
        }
        cout<<"down="<<d<<endl;
        down = dfs(maze, cnt_down-1, vector<int>{d-1,start[1]}, destination, visit, dp);
        }
        if(l>=0){
        int cnt_left = cnt;
        while(l>=0 && maze[start[0]][l]!=1) {l--; cnt_left++;}
        left =dfs(maze, cnt_left-1, vector<int>{start[0],l+1}, destination, visit, dp);
        }
        if(r<n) {
        int cnt_right = cnt;
        while(r<n && maze[start[0]][r]!=1) {r++;cnt_right++;}
        right = dfs(maze, cnt_right-1, vector<int>{start[0],r-1}, destination, visit, dp);
        }
        dp[start[0]][start[1]] = min(min(up,down), min(left, right));
        return dp[start[0]][start[1]];
        }
};
