class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n==0) return vector<string>{};
        vector<string> rst;
        vector<char> num1 = {'0','1','8','6','9'};
        vector<char> num2 = {'0','1','8','9','6'};
        int indx = 0;
        string list(n, '0');
        dfs(n, indx, num1, num2, list, rst);
        return rst;
    }
    
    void dfs(int n, int indx, vector<char>& num1, vector<char>& num2, string& list, vector<string>& rst) {
        int left = indx;
        int right = n-indx-1;
        if(left>right) {
            rst.push_back(list);
            return;
        }
        string tmp = list;
        if(left==right) {
            for(int i=0; i<3; i++) {
                list[left] = num1[i];
                dfs(n, indx+1, num1, num2, list, rst);
                list = tmp;
            }
        }
        else {
            for(int i=0; i<num1.size(); i++) {
                if(indx==0 && i==0) continue;
                list[left] = num1[i];
                list[right] = num2[i];
                dfs(n, indx+1, num1, num2, list, rst);
                list = tmp;
            }
        }
    }
};
