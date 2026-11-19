class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

         int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  

        vector<vector<int>> visited(n, vector<int>(n, 0));

          queue<tuple<int,int,int>> q;

        q.push({0, 0, 1});

        visited[0][0] = 1;

        while (!q.empty()) {

            auto [row, col, dis] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {

                if (row == n - 1 && col == n - 1) {
                    return dis;
                }

                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0 && visited[nr][nc] == 0) {

                    visited[nr][nc] = 1;

                    q.push({nr, nc, dis + 1});
                }
            }
        }

          return -1;
    }
};