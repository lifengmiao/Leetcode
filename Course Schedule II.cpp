class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res, in(numCourses,0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto p:prerequisites) {
            graph[p.second].push_back(p.first);
            in[p.first]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            res.push_back(tmp);
            for(auto a:graph[tmp]) {
                in[a]--;
                if(in[a]==0) q.push(a);
            }
        }
        for(int i=0;i<numCourses;i++) {
            if(in[i]!=0) return vector<int>();
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> inD(numCourses, 0);
        queue<int> mQ;
        for(auto it:prerequisites) {
            inD[it.second]++;
            
        }
        for(int i=0; i<inD.size(); i++) {
            if(inD[i]==0) {
                mQ.push(i);
            }
        }
        
        while(!mQ.empty()) {
            auto it = mQ.front();
            mQ.pop();
            res.push_back(it);
            for(auto neib:prerequisites) {
                if(neib.first==it){
                    inD[neib.second]--;
                    if(inD[neib.second]==0){
                        mQ.push(neib.second);
                    }
                }
            }
            
        }
        cout<<"end"<<endl;
        if(res.size()==numCourses) return vector<int> (res.rbegin(), res.rend());
        else return vector<int>();
    }
};
