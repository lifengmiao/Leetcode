class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = n;
        unordered_map<int, int> root;
        for(auto it:edges) {
            int x = findRoot(root, it.first), y=findRoot(root, it.second);
            if(x!=y) {
                res --;
                root[x]=y;
            }
        }
    
        return res;
    }
    
    int findRoot(unordered_map<int, int>& root, int i) {
        if(!root.count(i)) root[i] = i;
        return root[i]==i?i:findRoot(root, root[i]);
    }
};
