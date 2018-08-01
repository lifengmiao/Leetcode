class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = n;
        unordered_map<int, int> root;
        for(auto it:edges) {
            int x = findRoot(root, it.first), y=findRoot(root, it.second);
            if(x!=y) {
                res --;
                root[x]=y;
            }
        }
    
        return res;
    }
    
    int findRoot(unordered_map<int, int>& root, int i) {
        if(!root.count(i)) root[i] = i;
        return root[i]==i?i:findRoot(root, root[i]);
    }
};
//DFS
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_set<int> visit;
        unordered_map<int, unordered_set<int>> graph;
        int res = 0;
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }
        for(int i = 0; i<n; i++) {
                // cout<<"start "<<(it->first)<<endl;
                if(!visit.count(i)) {
                    res ++;
                    dfs(i, graph, visit);
                }
                    
        }
        return res;
    }
    
    void dfs(int i, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visit) {
        if(visit.count(i)) return;
        
        visit.insert(i);
        for(auto it:graph[i]) {
            // cout<<"inside "<<it<<endl;
            dfs(it, graph, visit);
        }
            
    }
};
