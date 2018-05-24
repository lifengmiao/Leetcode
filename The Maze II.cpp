/*
其中dists[i][j]表示到达(i,j)这个位置时需要的最小步数，我们都初始化为整型最大值，在后在遍历的过程中不断用较小值
来更新每个位置的步数值，最后我们来看终点位置的步数值，如果还是整型最大值的话，说明没法在终点处停下来，返回-1，
否则就返回步数值
*/
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX)); //distence from start to [i,j]
        dists[start[0]][start[1]] = 0;
        helper(maze, start[0], start[1], destination, dists);
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
    void helper(vector<vector<int>>& maze, int i, int j, vector<int>& destination, vector<vector<int>>& dists) {
        if (i == destination[0] && j == destination[1]) return;
        int m = maze.size(), n = maze[0].size();
        for (auto d : dirs) {
            int x = i, y = j, dist = dists[x][y];
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                x += d[0];
                y += d[1];
                ++dist;
            }
            x -= d[0];
            y -= d[1];
            --dist;
            if (dists[x][y] > dist) {
                dists[x][y] = dist;
                helper(maze, x, y, destination, dists);
            }
        }
    }
};

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
