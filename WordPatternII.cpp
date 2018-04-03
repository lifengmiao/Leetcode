/*
只有两种情况，dfs往下走
1. 两个map都不存在当前key：分别加入当前key，往下走，回溯的时候要删除当前加入的key
2. 两个map都存在当前key：如果当前key match，往下走，回溯时不需要删除，因为当前没有加入key
*/
/*
We can solve this problem using backtracking, we just have to keep trying to use a character in the pattern to match different length of substrings in the input string, keep trying till we go through the input string and the pattern.

For example, input string is "redblueredblue", and the pattern is "abab", first let’s use 'a' to match "r", 'b' to match "e", then we find that 'a' does not match "d", so we do backtracking, use 'b' to match "ed", so on and so forth …

When we do the recursion, if the pattern character exists in the hash map already, we just have to see if we can use it to match the same length of the string. For example, let’s say we have the following map:

'a': "red"

'b': "blue"

now when we see 'a' again, we know that it should match "red", the length is 3, then let’s see if str[i ... i+3] matches 'a', 
where i is the current index of the input string. Thanks to StefanPochmann’s suggestion, in Java we can elegantly use str.startsWith(s, i) to do the check.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        map<char, string> p2s;
        map<string, char> s2p;
        return dfs(pattern, str, 0, 0, p2s, s2p);
    }
    
    bool dfs(string pattern, string str, int pp, int sp, map<char, string>& p2s, map<string, char>& s2p) {
        if(pp==pattern.length() && sp==str.length()) return true;
        for (int k=sp; k<str.length();k++) {
            if(p2s.find(pattern[pp])==p2s.end() && s2p.find(str.substr(sp,k-sp+1))==s2p.end()) {
                p2s[pattern[pp]]=str.substr(sp,k-sp+1);
                s2p[str.substr(sp,k-sp+1)]=pattern[pp];
                if(dfs(pattern, str, pp+1, k+1, p2s, s2p)) return true;
                p2s.erase(pattern[pp]);
                s2p.erase(str.substr(sp,k-sp+1));
            }
            else {
                if(p2s.find(pattern[pp])!=p2s.end() && s2p.find(str.substr(sp,k-sp+1))!=s2p.end()) {
                    if(p2s[pattern[pp]]==str.substr(sp,k-sp+1) && s2p[str.substr(sp,k-sp+1)]==pattern[pp]) {
                        if(dfs(pattern, str, pp+1, k+1, p2s, s2p)) return true;
                    }
                }
            }
        }
        return false;
    }

};
