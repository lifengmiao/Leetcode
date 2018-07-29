//本质是有向图最短路径，用BFS。关键点是怎样找到一个当前stop的neighbors，这里bus相当于桥梁链接stops，所以找stop的neighbors首先找stop链接的所有bus，
//再找每个bus链接的其他stops即是neighbors

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;
    
    unordered_map<int, vector<int>> m; //stop -> buses
    for (int i = 0; i < routes.size(); ++i)
      for (const int stop : routes[i]) // routes is bus -> stops
        m[stop].push_back(i);
    
    vector<int> visited(routes.size(), 0); //visited buses
    queue<int> q;
    q.push(S); //stops in queue
    int buses = 0;
    
    while (!q.empty()) {
      int size = q.size(); //level traversal
      ++buses;
      while (size--) {
        int curr = q.front(); q.pop();        
        for (const int bus : m[curr]) {
          if (visited[bus]) continue;          
          visited[bus] = 1;
          for (int stop : routes[bus]) {
            if (stop == T) return buses;            
            q.push(stop);
          }
        }        
      }      
    }
    return -1;
  }
};
