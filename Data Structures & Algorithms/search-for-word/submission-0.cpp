class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool check = dfs(0, i, j, row, col, board, visited, word);
                if (check == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int ind, int i, int j, int row, int col, vector<vector<char>>& board,
             vector<vector<bool>>& visited, string word) {
        if (ind == word.size()) {
            return true;
        }

        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] == true ||
            board[i][j] != word[ind]) {
            return false;
        }
        visited[i][j] = true;

        bool check = dfs(ind + 1, i + 1, j, row, col, board, visited, word) ||
                     dfs(ind + 1, i - 1, j, row, col, board, visited, word) ||
                     dfs(ind + 1, i, j + 1, row, col, board, visited, word) ||
                     dfs(ind + 1, i, j - 1, row, col, board, visited, word);

        visited[i][j] = false;

        return check;
    }
};
