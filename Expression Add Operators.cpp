class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        if(n==0) return vector<string>{};
        vector<string> rst;
        string list;
        int indx=0;
        long cumuVal = 0;
        long preVal = 0;
        dfs(num, target, indx, cumuVal, preVal, list, rst);
        return rst;
    }
    
    void dfs(string num, int target, int indx, long cumuVal, long preVal, string& list, vector<string>& rst) {
        if(indx==num.length() && cumuVal==target) {
            rst.push_back(list);
            return;
        }
        for(int i=indx; i<num.length(); i++) {
            if(num[indx]=='0' && i!=indx) return;
            int len = list.length();
            long curVal = stol(num.substr(indx,i-indx+1));
            if (indx==0) {
                list += num.substr(indx, i-indx+1);
                dfs(num, target, i+1, curVal, curVal, list, rst);
                list = list.substr(0,len);
            }
            else {
                list += '+' + num.substr(indx,i-indx+1);
                dfs(num, target, i+1, cumuVal+curVal, curVal, list, rst);
                list = list.substr(0,len);
                list += '-' + num.substr(indx,i-indx+1);
                dfs(num, target, i+1, cumuVal-curVal, -curVal, list, rst);
                list = list.substr(0,len);
                list += '*' + num.substr(indx,i-indx+1);
                dfs(num, target, i+1, cumuVal-preVal+preVal*curVal, preVal*curVal, list, rst);
                list = list.substr(0,len);
            }
        }
        
    }
};
