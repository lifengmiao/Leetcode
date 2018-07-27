class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> visit(graph.size(),0);
        for(int i=0; i<graph.size(); i++) {
            int tmp = dfs(i,graph, visit);
            cout<<tmp<<endl;
            if(tmp<=i)
                res.push_back(i);
        }
        return res;
    }
    
    int dfs(int i, vector<vector<int>>& graph, vector<int>& visit) {
        // cout<<"start="<<i<<endl;
        if(graph[i].size()==0)
            {cout<<"return"<<endl;return 0;}
        if(visit[i]==1) {cout<<"visit"<<endl;return 0;}
        visit[i]=1;
        // cout<<"visit"<<i<<"="<<visit[i]<<endl;
        int mL=0;
        for(auto it:graph[i]) {
            // cout<<"neighbor="<<it<<endl;
            int tmp = dfs(it, graph, visit);
            mL = max(mL, tmp);
        }
        visit[i]=0;
        return mL+1;
    }
};
