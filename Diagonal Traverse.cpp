/*
向右上移动的话要坐标加上[-1, 1]，向左下移动的话要坐标加上[1, -1]，那么难点在于我们如何处理越界情况，
越界后遍历的方向怎么变换。向右上和左下两个对角线方向遍历的时候都会有越界的可能，但是除了左下角和右上
角的位置越界需要改变两个坐标之外，其余的越界只需要改变一个。那么我们就先判断要同时改变两个坐标的越界
情况，即在右上角和左下角的位置。如果在右上角位置还要往右上走时，那么要移动到它下面的位置的，那么如果
col超过了n-1的范围，那么col重置为n-1，并且row自增2，然后改变遍历的方向。同理如果row超过了m-1的范围，
那么row重置为m-1，并且col自增2，然后改变遍历的方向。然后我们再来判断一般的越界情况，如果row小于0，
那么row重置0，然后改变遍历的方向。同理如果col小于0，那么col重置0，然后改变遍历的方向。参见代码如下：
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n=matrix[0].size();
        int  c=0, r = 0, d = 0;
        vector<vector<int>> direction = {{-1,1},{1,-1}};
        vector<int> rst (m*n);
        for(int i=0; i<m*n; i++) {
            rst[i] = matrix[r][c];
            r += direction[d][0];
            c += direction[d][1];
            if(r>=m) {
                r = m-1;
                c += 2;
                d = 1-d;
            }
            if(c>=n) {
                c = n-1;
                r += 2;
                d = 1-d;
            }
            if(r<0) {
                r = 0;
                d = 1-d;
            }
            if(c<0) {
                c = 0;
                d = 1-d;
            }
        }
        return rst;
    }
};
