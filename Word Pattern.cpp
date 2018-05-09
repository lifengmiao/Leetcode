class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> p2i;
        map<char, string> i2p;
        istringstream in(str);
        int i=0, n=pattern.length();
        for(string curr; in>>curr; i++) {
            if(p2i.find(curr)==p2i.end() && i2p.find(pattern[i])==i2p.end()) {
                p2i[curr]=pattern[i];
                i2p[pattern[i]]=curr;
            }
            else {
                if(p2i.find(curr)==p2i.end()) return false;
                if(i2p.find(pattern[i])==i2p.end()) return false;
                if(p2i[curr]!=pattern[i]) return false;
                if(i2p[pattern[i]]!=curr) return false;
            }
        }
        return i==n;
    }
};
