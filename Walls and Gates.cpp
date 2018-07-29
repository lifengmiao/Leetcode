//BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size(), n=m==0?0:rooms[0].size();
        queue<pair<int, int>> mQ;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(rooms[i][j]==0)
                    mQ.push(make_pair(i,j));
            }
        
        while(!mQ.empty()) {
            pair<int,int> cur = mQ.front();mQ.pop();
            int i = cur.first, j=cur.second;
            if(i>=0 && i<m && j-1>=0 && j<n && rooms[i][j-1]>rooms[i][j]+1) {
                rooms[i][j-1] = rooms[i][j]+1;
                mQ.push(make_pair(i, j-1));
            }
            if(i>=0 && i<m && j>=0 && j+1<n && rooms[i][j+1]>rooms[i][j]+1) {
                rooms[i][j+1] = rooms[i][j]+1;
                mQ.push(make_pair(i, j+1));
            }
            if(i-1>=0 && i<m && j>=0 && j<n && rooms[i-1][j]>rooms[i][j]+1) {
                rooms[i-1][j] = rooms[i][j]+1;
                mQ.push(make_pair(i-1, j));
            }
            if(i>=0 && i+1<m && j>=0 && j<n && rooms[i+1][j]>rooms[i][j]+1) {
                rooms[i+1][j] = rooms[i][j]+1;
                mQ.push(make_pair(i+1, j));
            }
        }
    }
};

//DFS

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) dfs(rooms, i, j, 0);
            }
        }
    }
    void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] < val) return;
        rooms[i][j] = val;
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i, j + 1, val + 1);
        dfs(rooms, i, j - 1, val + 1);
    }
};
