
//self Memory Limit Exceeded 
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, int> hash;
        for(auto it:edges) {
            if(!hash.count(it.first)) hash[it.first] = it.first;
            if(!hash.count(it.second)) hash[it.second] = it.second;
            int p = findRoot(hash, it.first), q = findRoot(hash, it.second);
            if(p==q) return false;
            else
                hash[p] = q;
        }
        
        // for(int i=1; i<n; i++) {
        //     if(findRoot(hash,i-1)!=findRoot(hash, i)) return false;
        // }
        return edges.size()==n-1;
    }
    
    int findRoot(unordered_map<int, int> hash, int i) {
        return hash[i]==i?i:findRoot(hash, hash[i]);
    }
};
