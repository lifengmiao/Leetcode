/*
note: there is no for loop in dfs
  for (int i=pos; i<word.length(); i++) 
That is because word.length() is the depth of the dfs, not the choose options. 
There are only two choose options:
  1. Add word[pos]
  2. Skip word[pos] : in this case, there are two subcases, a. cnt>0; b. cnt==0
So there are two dfs inside
*/
/*
The idea is: for every character, we can keep it or abbreviate it. To keep it, 
we add it to the current solution and carry on backtracking. To abbreviate it, 
we omit it in the current solution, but increment the count, which indicates 
how many characters have we abbreviated. When we reach the end or need to put a 
character in the current solution, and count is bigger than zero, we add the number into the solution.
*/
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> out;
        string list;
        int cnt;
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
        dfs(out, list, pos+1, word, cnt+1);
        if(cnt>0) {
            list += to_string(cnt)+word[pos];
            dfs(out, list, pos+1, word, 0);
        }
        else {
            list += word[pos];
            dfs(out, list, pos+1, word, 0);
        }
        list = list.substr(0, len);
    }
};
