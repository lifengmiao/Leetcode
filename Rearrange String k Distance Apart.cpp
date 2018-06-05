class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        string res;
        int len = (int)str.size();
        unordered_map<char, int> m; //hash table只是用来生成 heap用的，生成heap之后就不用了
        priority_queue<pair<int, char>> q;
        for (auto a : str) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({it->second, it->first});
        }
        while (!q.empty()) {
            vector<pair<int, int>> v; //用来存临时改变了的element，循环完后放入heap
            int cnt = min(k, len); //循环到最后的时候，剩下str的len可能小于k，len为剩下str的length
            for (int i = 0; i < cnt; ++i) {
                if (q.empty()) return "";
                auto t = q.top(); q.pop(); //临时移除，后面会加回来
                res.push_back(t.second);
                if (--t.first > 0) v.push_back(t);//放置之后还有剩余，加回heap
                --len; //剩下的字母数 -1
            }
            for (auto a : v) q.push(a);
        }
        return res;
    }
};
