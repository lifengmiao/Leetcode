/*
这道题是之前那道Sentence Similarity的拓展，那道题说单词之间不可传递，
于是乎这道题就变成可以传递了，那么难度就增加了。不过没有关系，还是用我
们的经典老三样来解，BFS，DFS，和Union Find。我们先来看BFS的解法，其
实这道题的本质是无向连通图的问题，那么首先要做的就是建立这个连通图的数
据结构，对于每个结点来说，我们要记录所有和其相连的结点，所以我们建立每个
结点和其所有相连结点集合之间的映射，比如对于这三个相似对(a, b), (b, c)，
和(c, d)，我们有如下的映射关系：

a -> {b}

b -> {a, c}

c -> {b, d}

d -> {c}

那么如果我们要验证a和d是否相似，就需要用到传递关系，a只能找到b，b可以找到a，c，
为了不陷入死循环，我们将访问过的结点加入一个集合visited，那么此时b只能去，c只能去d，
那么说明a和d是相似的了。那么我们用for循环来比较对应位置上的两个单词，如果二者相同，
那么直接跳过去比较接下来的。否则就建一个访问即可visited，建一个队列queue，然后把words1
中的单词放入queue，建一个布尔型变量succ，标记是否找到，然后就是传统的BFS遍历的写法了，
从队列中取元素，如果和其相连的结点中有words2中的对应单词，标记succ为true，并break掉。
否则就将取出的结点加入队列queue，并且遍历其所有相连结点，将其中未访问过的结点加入队列queue继续循环，
参见代码如下：
*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
            m[pair.second].insert(pair.first);
        }    
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            unordered_set<string> visited;
            queue<string> q{{words1[i]}};
            bool succ = false;
            while (!q.empty()) {
                auto t = q.front(); q.pop();
                if (m[t].count(words2[i])) {
                    succ = true; break;
                }
                visited.insert(t);
                for (auto a : m[t]) {
                    if (!visited.count(a)) q.push(a);
                }
            }
            if (!succ) return false;
        }    
        return true;
    }
};
