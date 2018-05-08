class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = m==0?0:board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if ((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O')
                    dfs(board, i, j);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j]=='S')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i<0 || i>=board.size()) return;
        if(j<0 || j>=board[0].size()) return;
        if(board[i][j]!='O') return;
        board[i][j] = 'S';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
