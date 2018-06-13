class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res;
        istringstream in(paragraph);
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> m;
        string cur;
        int maxCnt = 0;
        while(in>>cur) {
            string tmp;
            for(char it:cur) {
                if(it>='A' && it<='Z')
                    tmp += it+32;
                else if(it>='a' && it<='z')
                    tmp += it;
            }
            if(s.count(tmp))
                continue;
            else {
                if(m.count(tmp))
                    m[tmp]++;
                else
                    m[tmp]= 1;
                if(m[tmp]>maxCnt) {
                    maxCnt = m[tmp];
                    res = tmp;
                }
            }
        }
        return res;
    }
};
