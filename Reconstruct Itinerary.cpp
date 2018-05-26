/*
tickets = [["JFK", "KUL"], ["JFK", "NRT"], ["MRT", "JFK"]]

那么建立的图如下：

JFK -> KUL, NRT

NRT -> JFK

由于multiset是按顺序存的，所有KUL会在NRT之前

这道题的本质是有向图的遍历问题，那么LeetCode关于有向图的题只有两道Course Schedule和Course Schedule II，
而那两道是关于有向图的顶点的遍历的，而本题是关于有向图的边的遍历。每张机票都是有向图的一条边，我们需要找出
一条经过所有边的路径，那么DFS不是我们的不二选择。先来看递归的结果，我们首先把图建立起来，通过邻接链表来建立。
由于题目要求解法按字母顺序小的，那么我们考虑用multiset，可以自动排序。等我们图建立好了以后，从节点JFK开始遍历，
只要当前节点映射的multiset里有节点，我们取出这个节点，将其在multiset里删掉，然后继续递归遍历这个节点，由于题
目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯
回去，将当前节点都存入结果，那么最后我们结果中存的顺序和我们需要的相反的，我们最后再翻转一下即可，参见代码如下：
*/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>>& m, string s, vector<string>& res) {
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
    }
};



/*
self TLE
*/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<vector<string>> rst;
        vector<string> list = {"JFK"};
        vector<bool> visit(tickets.size(), false);
        dfs(tickets, list, "JFK", visit, rst );
        sort(rst.begin(), rst.end());
        return rst[0];
    }
    
    void dfs(vector<pair<string, string>> tickets, vector<string>& list, string start, vector<bool>& visit, vector<vector<string>>& rst) {
        if(list.size()==tickets.size()+1) {
            rst.push_back(list);
            return;
        }
        for(int i=0; i<tickets.size(); i++) {
            if(visit[i]) continue;
            if(tickets[i].first == start) {
                visit[i]=true;
                list.push_back(tickets[i].second);
                dfs(tickets, list, tickets[i].second, visit, rst);
                list.pop_back();
                visit[i]=false;
            }
        }
        return;
    }
};
