/*
BFS
越在queue前面的点，离起始点越近。所以要用visit记录前面已经访问过的点，因为前面已经访问过该点并赋值，后面如果再来访问，
其付的值一定大于或等于之前付的值，所以没有必要再访问一次

我们对于每一个建筑（‘1’）的位置都进行一次全图的BFS遍历，每次都建立一个dist的距离场，由于我们BFS遍历需要标记应经访问过的位置，
而我们并不想建立一个visit的二维矩阵，那么怎么办呢，这里用一个小trick，我们第一遍历的时候，都是找0的位置，遍历完后，我们
将其赋为-1，这样下一轮遍历我们就找-1的位置，然后将其都赋为-2，以此类推直至遍历完所有的建筑物，然后在遍历的过程中更新dist和sum的值，
注意我们的dist算是个局部变量，每次都初始化为grid，真正的距离场累加在sum中，由于建筑的位置在grid中是1，所以dist中初始化也是1，
累加到sum中就需要减1，我们用sum中的值来更新结果res的值，最后根据res的值看是否要返回-1，参见代码如下：

notes: 和wall and gates 的不同在于，wall and gates首先把所有的gates push到queue中，因为他是求最小值，不需要每个gate建立一个dist，
只需要在扫的过程中更新为最小的值即可；而本题是求和，所以每个建筑‘1’，都要建立一个dist
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int a = q.front().first, b = q.front().second; q.pop();
                        for (int k = 0; k < dirs.size(); ++k) {
                            int x = a + dirs[k][0], y = b + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y]; //only change original '0', don't change original '1', so it doesn't effect dist
                                dist[x][y] = dist[a][b] + 1; //local的最值 （for one building）
                                sum[x][y] += dist[x][y] - 1; //global的最值 (for all buildings)
                                q.push({x, y});
                                res = min(res, sum[x][y]); //前几次其实没有用，因为每次新的building会reset to INFI, 只有最后一次才是最终结果
                                cout<<"x="<<x<<"y="<<y<<"sum="<<sum[x][y]<<"res="<<res<<endl;
                            }
                        }
                    }
                    --val;                    
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
//Wall and gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) q.push({i, j});   
            }
        }
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second; q.pop();
            for (int k = 0; k < dirs.size(); ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};
