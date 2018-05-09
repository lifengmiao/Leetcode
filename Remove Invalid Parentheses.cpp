class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int leftcnt=0;
        int rightcnt = 0;
        int opencnt = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='(')
                leftcnt ++;
            else if(s[i]==')')
                if(leftcnt>0) leftcnt--;
                else
                    rightcnt++;
        }
        set<string> rst;
        string list;
        dfs(s, 0, leftcnt, rightcnt, opencnt, list, rst);
        return vector<string>(rst.begin(), rst.end());
    }
    
    void dfs(string& s, int indx, int leftcnt, int rightcnt, int opencnt, string& list, set<string>& rst) {
        
        if(indx==s.length()&&leftcnt==0&&rightcnt==0&&opencnt==0) {
            rst.insert(list);
            return;
        }
        if(indx==s.length()||leftcnt<0||rightcnt<0||opencnt<0) 
            return;
        
        int len =list.length();
        if(s[indx]=='(') {
            dfs(s, indx+1, leftcnt-1,rightcnt, opencnt,list,rst);
            list += '(';
            dfs(s, indx+1, leftcnt, rightcnt, opencnt+1, list, rst);
        }
        else if(s[indx]==')') {
            dfs(s, indx+1, leftcnt,rightcnt-1, opencnt,list,rst);
            list += ')';
            dfs(s, indx+1, leftcnt, rightcnt, opencnt-1, list, rst);
        }
        else {
            list += s[indx];
            dfs(s, indx+1, leftcnt, rightcnt, opencnt, list, rst);
        }
            
        list = list.substr(0,len);  
    }
};
