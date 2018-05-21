class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string maxStr = "";
        for(string it:d) {
            // cout<<it<<endl;
            if(isSubsequence(it, s)) {
                // cout<<"true"<<endl;
                if(it.length()>maxStr.length() || (it.length()==maxStr.length() && it < maxStr))
                    maxStr = it;
            }
        }
        return maxStr;
    }
    
    bool isSubsequence(string x, string s) {
        int j = 0;
        for(int i=0; i<s.length() && j<x.length(); i++) {
            if(x[j]==s[i])
                j++;
        }
        return j==x.length();
    }
};
