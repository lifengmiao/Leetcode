//Notes: hashmap 建立old node和new node之间的联系，扫到一个old node，如果有对应的new node，说明clone过，直接用。

//DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> Map;
        return clone(node, Map);
    }
    
    UndirectedGraphNode* clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& Map) {
        if(!node) return NULL;
        if(Map.count(node->label)) return Map[node->label];
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        Map[node->label] = new_node;
        for(int i=0; i<node->neighbors.size(); i++) {
            UndirectedGraphNode* new_neighbor = clone(node->neighbors[i], Map);
            (new_node->neighbors).push_back(new_neighbor);
        }
        return new_node;
    }
};
//BFS 先建立新旧联系，再入queue
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        queue<UndirectedGraphNode *> mQ;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
        UndirectedGraphNode * head = new UndirectedGraphNode(node->label);
        hash[node] = head;
        mQ.push(node);
        while(!mQ.empty()) {
            UndirectedGraphNode * cur = mQ.front();
            mQ.pop();
            for(UndirectedGraphNode * it:cur->neighbors) {
                if(hash.count(it)) hash[cur]->neighbors.push_back(hash[it]);
                else {
                    UndirectedGraphNode * new_neighbor = new UndirectedGraphNode(it->label);
                    hash[cur]->neighbors.push_back(new_neighbor);
                    hash[it] = new_neighbor;
                    mQ.push(it);
                }
            }            
        }
        return head;
    }
};
