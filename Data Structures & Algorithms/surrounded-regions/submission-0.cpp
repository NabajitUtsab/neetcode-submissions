/* We have to do three things.
1. We will capture the unsurrounded regions at border
2. Then we will capture the surrounded regions
3. We will release the captured unsurrounded regions
*/
class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // capturing the unsurrounded regions at border
        for (int i = 0; i < row; i++) {
            // Borders rows
            if (board[i][0] == 'O') {
                capture(i, 0, board);
            }

            if (board[i][col - 1] == 'O') {
                capture(i, col - 1, board);
            }
        }
        for (int i = 0; i < col; i++) {
            // Borders cols
            if (board[0][i] == 'O') {
                capture(0, i, board);
            }

            if (board[row - 1][i] == 'O') {
                capture(row - 1, i, board);
            }
        }

        // capturing the surrounded regions
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // releasing the captured unsurrounded regions
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void capture(int r, int c, vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        if (r < 0 || r >= row || c < 0 || c >= col || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        capture(r - 1, c, board);
        capture(r, c + 1, board);
        capture(r + 1, c, board);
        capture(r, c - 1, board);
    }
};
