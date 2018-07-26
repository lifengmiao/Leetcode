class Solution {
public:     
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> mQ;
        mQ.push(0);
        set<int> visit;
        visit.insert(0);
        while(!mQ.empty()) {
            int cur = mQ.front(); mQ.pop();
            for(auto it:rooms[cur]) {
                if(!visit.count(it)) {
                    visit.insert(it);
                    mQ.push(it);
                }
            }
        }
        for(int i=0; i<rooms.size();  i++) {
            if(!visit.count(i)) return false;
        }
        return true;
    }
    
};


// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int N = rooms.size();
//         vector<int> visit(N,0);
        
//         dfs(0, rooms, visit);
//         for(int it:visit) {
//             if(it==0) return false;
//         }
//         return true;
//     }
    
//     void dfs(int i, vector<vector<int>>& rooms,  vector<int>& visit) {
//         if(visit[i]) return;
//         visit[i]=1;
//         for(auto it:rooms[i]) {
//             dfs(it, rooms, visit);
//         }
//     }
// };
