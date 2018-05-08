class Solution {
public:
    int cnt=0;
    int strobogrammaticInRange(string low, string high) {
        vector<char> num1 = {'0','1','8','6','9'};
        vector<char> num2 = {'0','1','8','9','6'};
        int m = low.length();
        int n = high.length();
        for (int i=m; i<=n; i++){
            string list(i, '0');
            dfs(i, 0, num1, num2, list, low, high);
        }
        return cnt;
    }
    
    void dfs(int n, int indx, vector<char>& num1, vector<char>& num2, string& list, string low, string high) {
        int left = indx;
        int right = n-indx-1;
        if(left>right) {
            if(stoi(list)>stoi(low) && stoi(high)>stoi(list))
                cnt++;
            return;
        }
        string tmp = list;
        if(left==right) {
            for(int i=0; i<3; i++) {
                list[left] = num1[i];
                dfs(n, indx+1, num1, num2, list, low, high);
                list = tmp;
            }
        }
        else {
            for(int i=0; i<num1.size(); i++) {
                if(indx==0 && i==0) continue;
                list[left] = num1[i];
                list[right] = num2[i];
                dfs(n, indx+1, num1, num2, list, low, high);
                list = tmp;
            }
        }
    }
};
