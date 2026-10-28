class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {

        int row = board.size();
        int col = board[0].size();

        if (i < 0 || i >= row || j < 0 || j >= col ||
            board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'P';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O')
                dfs(board, 0, i);

            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i);
        }

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }
};