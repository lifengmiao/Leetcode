class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=m?board[0].size():0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int cnt = 0;
                for (int ii=max(i-1,0); ii<min(i+2,m); ii++) {
                    for (int jj=max(j-1,0); jj<min(j+2,n); jj++) {
                        cnt = cnt + (board[ii][jj]&1);
                    }
                }
                cnt -= board[i][j]; //count self previously
                if(board[i][j]==1) {
                    if(cnt==2 || cnt==3)
                        board[i][j] |= 2;
                }
                else {
                    if(cnt ==3)
                        board[i][j] |= 2;
                }
            }
        }
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                board[i][j] >>= 1;
            }
        
    }
};
