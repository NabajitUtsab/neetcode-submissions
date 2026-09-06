class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        queue<pair<pair<int, int>, int>> q;
        int time = 0;

        // First we will store the rotten oranges in a queue for BFS
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, time});
                    vis[i][j] = true;
                }
            }
        }

        // This is for up,right,down,left
        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};

        // now we will apply the BFS
        while (!q.empty()) {
            int nR = q.front().first.first;
            int nC = q.front().first.second;

            int t = q.front().second;

            q.pop();

            time = max(time, t);

            // checking up right down left
            for (int i = 0; i < 4; i++) {
                int checkRow = r[i] + nR;
                int checkCol = c[i] + nC;

                if (checkRow >= 0 && checkRow < row && checkCol >= 0 && checkCol < col &&
                    grid[checkRow][checkCol] == 1 && vis[checkRow][checkCol] == false) {
                    q.push({{checkRow, checkCol}, t + 1});
                    grid[checkRow][checkCol] = 2;
                    vis[checkRow][checkCol] = true;
                }
            }
        }

        // if any fresh orange remain then return -1
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
