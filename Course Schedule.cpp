class Solution {
public:
    //DFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.first].push_back(a.second); //or graph[a.second].push_back(a.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    
    bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false; //back to used course, has circle
        if (visit[i] == 1) return true; //already checked, can finish, memorized search
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
        
    /*
    //BFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int>(0)); //adjunct representation
        vector<int> in(numCourses, 0); //in degree of each node
        //build direct graph
        for(auto p:prerequisites) {
            graph[p.second].push_back(p.first);
            in[p.first]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(in[i]==0) 
                q.push(i);
        }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto node:graph[t]) {
                in[node]--;
                if(in[node]==0) q.push(node);
            }
        }
        for(int i=0; i<numCourses; i++) {
            if(in[i]!=0) return false;
        }
        return true;
    }
    */
};
