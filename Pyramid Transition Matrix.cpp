//DFS with two entries
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {   
        unordered_map<string, unordered_set<char>> m;
        for (string str : allowed) {
            m[str.substr(0, 2)].insert(str[2]);
        }
        return helper(bottom, "", m);
    }
    bool helper(string cur, string above, unordered_map<string, unordered_set<char>>& m) {
        if (cur.size() == 2 && above.size() == 1) return true;
        if (above.size() == cur.size() - 1) return helper(above, "", m); //first entry
        int pos = above.size();
        string base = cur.substr(pos, 2);
        if (m.count(base)) {
            for (char ch : m[base]) {
                if (helper(cur, above + string(1, ch), m)) { //sesond entry
                    return true;
                }
            }
        }
        return false;
    }
};

//self not finish
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.length()==1) return true;
        vector<string> list;
        for(int i=1; i<bottom.size(); i++) {
            string tmp = bottom.substr(i-1,2);
            for(int j=0; j<allowed.size(); j++) {
                if(allowed[j].substr(0,2)==tmp) {
                    list[i-1] += allowed[j][2];
                }
            }
        }
        vector<string> bottom_new;
        findNext(0, "", list, bottom_new);
        for(int i=0; i<bottom_new.size(); i++) {
            if(pyramidTransition(bottom_new[i], allowed)) return true;
        }
        return false;
    }
    
    void findNext(int level, string out, vector<string>& list, vector<string>& res) {
        if (level==list.size()) {
            res.push_back(list);
            return;
        }
        int len = out.length();
        for(int i=0; i<list[level].length(); i++) {
            out += list[level][i];
            findNext(level+1, out, list, res);
            out = out.subsrt(0, len);
        }
    }
};
