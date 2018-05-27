/*
下面这种解法就是碉堡了的联合查找Union Find了，这种解法的核心是一个getRoot函数，如果两个元素属于同一个群组的话，调用
getRoot函数会返回相同的值。主要分为两部，第一步是建立群组关系，suppose开始时每一个元素都是独立的个体，各自属于不同的群组。
然后对于每一个给定的关系对，我们对两个单词分别调用getRoot函数，找到二者的祖先结点，如果从未建立过联系的话，那么二者的祖
先结点时不同的，此时就要建立二者的关系。等所有的关系都建立好了以后，第二步就是验证两个任意的元素是否属于同一个群组，就只
需要比较二者的祖先结点都否相同啦。是不是有点深度学习的赶脚，先建立模型training，然后再test。哈哈，博主乱扯的，二者并没有
什么联系。我们保存群组关系的数据结构，有时用数组，有时用哈希map，看输入的数据类型吧，如果输入元素的整型数的话，用root数组
就可以了，如果是像本题这种的字符串的话，需要用哈希表来建立映射，建立每一个结点和其祖先结点的映射。注意这里的祖先结点不一定
是最终祖先结点，而最终祖先结点的映射一定是最重祖先结点，所以我们的getRoot函数的设计思路就是要找到最终祖先结点，那么就是当
结点和其映射结点相同时返回，否则继续循环，可以递归写，也可以迭代写，这无所谓。注意这里第一行判空是相当于初始化，这个操作可
以在外面写，就是要让初始时每个元素属于不同的群组，参见代码如下
*/
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        unordered_map<string, string> mMap;
        for(auto it:pairs) {
            string x = getRoot(mMap, it.first);
            string y = getRoot(mMap, it.second);
            if(x!=y) mMap[x]=y;
        }
        for(int i=0; i<words1.size(); i++) {
            if(getRoot(mMap, words1[i])!=getRoot(mMap, words2[i])) return false;
        }
        return true;
    }
    
    string getRoot(unordered_map<string, string>& mMap, string word) {
        if(!mMap.count(word)) mMap[word]=word;
        return mMap[word]==word?word:getRoot(mMap, mMap[word]);
    }
};
/*
另外一种写法
*/
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        unordered_map<string, string> mMap;
        for(auto it:pairs) {
            string x,y;
            if(!mMap.count(it.first)) {
                mMap[it.first] = it.first;
                x = it.first;
            }
            else {
                x = getRoot(mMap, it.first);
            }
            if(!mMap.count(it.second)) {
                mMap[it.second] = it.second;
                y = it.second;
            }
            else {
                y = getRoot(mMap, it.second);
            }
            if(x!=y) mMap[x]=y;
        }
        for(int i=0; i<words1.size(); i++) {
            if(getRoot(mMap, words1[i])!=getRoot(mMap, words2[i])) return false;
        }
        return true;
    }
    
    string getRoot(unordered_map<string, string>& mMap, string word) {
        return mMap[word]==word?word:getRoot(mMap, mMap[word]);
    }
};
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
