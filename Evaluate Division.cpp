class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> rst;
        //build graph
        unordered_map<string, unordered_map<string, double>> graph; //direction graph with weight
        for(int i=0; i<equations.size(); i++) {
            string f=equations[i].first, s=equations[i].second;
            graph[f][s] = values[i];
            graph[s][f] = 1.0/values[i];
        }
        
        //use graph
        for(auto it:queries) { //for each item in queries, run independent dfs
            string start = it.first, end = it.second;
            if(!graph.count(start) || !graph.count(end)) rst.push_back(-1.0);
            else {
                int preLen = rst.size();
                unordered_set<string> visit;//for each item in queries, clear visit
                dfs(graph, start, end, visit, rst, 1.0);
                if (rst.size()==preLen) rst.push_back(-1.0); //every item should have one result, even can't solve
            }
        }
        return rst;
    }
    
    void dfs(unordered_map<string, unordered_map<string, double>>& graph, string start, string end, unordered_set<string>& visit, vector<double>& rst, double cur) {
        if(start==end) {
            rst.push_back(cur);
            return;
        }
        for(auto it:graph[start]) {
            string cur_str = it.first;
            if(visit.find(cur_str)!=visit.end()) continue;
            visit.insert(start); //start been visited, not cur_str!!!!!!!
            dfs(graph, cur_str, end, visit, rst, cur*it.second);
            visit.erase(start);
        }
    }
};
