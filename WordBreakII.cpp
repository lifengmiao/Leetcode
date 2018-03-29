class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> mySet(wordDict.begin(), wordDict.end());
        vector<string> out;
        string list;
        vector<bool> canbreak = canBreak(s, mySet);
        dfs(s, 0, list, out, mySet, canbreak);
        return out;
    }
    
    void dfs(string s, int indx, string list, vector<string>& out, set<string> mySet, vector<bool> canbreak) {
        if(indx==s.length()) {
            out.push_back(list.substr(1));
        }
        if(canbreak[indx]==false) return; //add branch cast to pass time limit
        for(int i=indx;i<s.length();i++)
            if(mySet.find(s.substr(indx, i+1-indx))!=mySet.end()) {
                dfs(s, i+1, list+" "+s.substr(indx, i+1-indx), out, mySet, canbreak);
            }
    }
    
    //For branch cast to pass time limit
    vector<bool> canBreak(string s, set<string> mySet) { 
        vector<bool> dp(s.length()+1, false); //dp[i] means if the substr[i:end] can be break
        dp[s.length()]=true;
        for(int i=s.length()-1; i>=0; i--) { //from end to start
            for(int j=i+1; j<=s.length(); j++) {
                if(dp[j] && mySet.find(s.substr(i,j-i))!=mySet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp;
    }
};
