class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        istringstream ss(input);
        vector<int> m(100,0);
        string line = "";
        while (getline(ss, line)) {
            int level = line.find_last_of('\t') + 1; //if no \t level=-1
            cout<<level<<endl;
            int len = line.substr(level).size();
            if (line.find('.') != -1) {
                res = max(res, m[level] + len);
            } else {
                //can't use m.push_back, since need to update m[level+1]
                m[level+1] = m[level] + len + 1; //+1 corresponding to '/'
            }
        }
        return res;
    }
};
