class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = m==0?0:board[0].size();
        int indx = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) 
                if(dfs(board, word, indx, i, j)) return true;
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int indx, int i, int j) {
        if (indx == word.length()) return true;
        if (i<0 || i>=board.size()) return false;
        if (j<0 || j>=board[0].size()) return false;
        if (board[i][j]!=word[indx]) return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        bool rst = (dfs(board, word, indx+1, i+1, j) ||
                    dfs(board, word, indx+1, i-1, j) ||
                    dfs(board, word, indx+1, i, j+1) ||
                    dfs(board, word, indx+1, i, j-1));
        board[i][j] = tmp;
        return rst;
                   
    }
};
