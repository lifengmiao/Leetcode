/*
我们建立一个二维数组jumps，用来记录两个数字键之间是否有中间键，然后再用一个一位数组visited来记录某个键是否被访问过，
然后我们用递归来解，我们先对1调用递归函数，在递归函数中，我们遍历1到9每个数字next，然后找他们之间是否有jump数字，
如果next没被访问过，并且jump为0，或者jump被访问过，我们对next调用递归函数。数字1的模式个数算出来后，由于1,3,7,9是对称的，
所以我们乘4即可，然后再对数字2调用递归函数，2,4,6,9也是对称的，再乘4，最后单独对5调用一次，然后把所有的加起来就是最终结果了，
参见代码如下
*/
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> visited(10, false); //use one more element for convinient access 1~9
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        res += helper(1, 1, 0, m, n, jumps, visited) * 4;
        res += helper(2, 1, 0, m, n, jumps, visited) * 4;
        res += helper(5, 1, 0, m, n, jumps, visited);
        return res;
    }
    int helper(int num, int len, int res, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) {
        if (len > n) return res;
        if (len >= m) ++res;
        visited[num] = true;
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                res = helper(next, len+1, res, m, n, jumps, visited);
            }
        }
        visited[num] = false;
        return res;
    }
}; 
