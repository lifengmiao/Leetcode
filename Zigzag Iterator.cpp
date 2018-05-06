/*
can extend to K inputs cases
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) mQ.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty()) mQ.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        int rst = *mQ.front().first;
        if(mQ.front().first+1!=mQ.front().second) {
            mQ.push(make_pair(mQ.front().first+1, mQ.front().second));
        }
        mQ.pop();
        return rst;
    }

    bool hasNext() {
        return !mQ.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> mQ;
};
