class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> out;
        string list="";
        int cnt=0;
        dfs(out, list, 0, word, cnt);
        return out;
    }
    
    void dfs(vector<string>& out, string& list, int pos, string& word, int cnt) {
        int len = list.length();
        if(pos==word.length()) {
            if (cnt>0)
                out.push_back(list+to_string(cnt));
            else
                out.push_back(list);
            return;
        }
        //don't keep
        dfs(out, list, pos+1, word, cnt+1);
        
        //keep
        if(cnt>0) {
            list += to_string(cnt)+word[pos];
            dfs(out, list, pos+1, word, 0);
            list = list.substr(0, len);
        }
        else {
            list += word[pos];
            dfs(out, list, pos+1, word, 0);
            list = list.substr(0, len);
        }

    }
};
