//BFS
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        vector<vector<int>> edges(101, vector<int>(101, -1));
        queue<int> q{{K}};
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        while (!q.empty()) {
            unordered_set<int> visited;
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= 100; ++v) {
                    if (edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

//DFS (time limit exceeded)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        vector<vector<int>> edges(101, vector<int>(101, -1));
        vector<int> dist(N + 1, INT_MAX);
        for (auto e : times) edges[e[0]][e[1]] = e[2];
        dfs(K, edges, dist, 0);
        for (int i = 1; i <= N; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
    
    void dfs(int cur, vector<vector<int>>& edges, vector<int>& dist, int delay) {
        if(dist[cur]<delay) return;
        dist[cur]=delay;
        for(int i=0; i<edges[cur].size(); i++){
            if(edges[cur][i]!=-1) {
                dfs(i, edges, dist, delay+edges[cur][i]);
            }
        }
    }
};
