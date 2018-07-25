/*
有向图
t->f
w->e
r->t
e->r

*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s; //有向图的边
        unordered_set<char> ch; //出现的字符
        vector<int> in(256, 0); //字符的入度 (有多少边指向它）
        queue<char> q;
        string res = "";
        //create ch
        for (auto a : words) ch.insert(a.begin(), a.end());
        //create s
        for (int i = 0; i < words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));//相邻字符串第一个不相同的字符
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return ""; //corner case： 'abcd' 不可能在 'abc'之前
        }
        for (auto a : s) ++in[a.second]; //初始入度
        for (auto a : ch) { //初始入度为0 则为root
            if (in[a] == 0) {
                q.push(a);
                res += a;
            } 
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) { //遍历所有边；本题没有建立graph的node数据结构，所以不是带着node循环，而是带着所有“边”循环
                if (a.first == c) {//找到以c开头的边
                    --in[a.second]; //root的child节点，root排除后，轮到child节点，所以child节点入度减一
                    if (in[a.second] == 0) {//可能有多个节点（root）指向该节点，只有当所有root都clear后，此节点才能入queue
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};
