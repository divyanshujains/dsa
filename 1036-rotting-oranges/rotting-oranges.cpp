class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        int fresh = 0;

        bool rotten = false;

        queue<pair<int, int>> q;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 2) {

                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        while (!q.empty()) {

            int size = q.size();
             bool rotten = false;

            for (int z = 0; z < size; z++) {

                pair<int, int> p = q.front();
                q.pop();

                int i = p.first;
                int j = p.second;

                for (int k = 0; k < 4; k++) {

                    int newRow = i + dx[k];
                    int newCol = j + dy[k];

                    if (newRow >= 0 && newRow < row && newCol >= 0 &&
                        newCol < col && grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        fresh--;
                        rotten = true;
                        q.push({newRow, newCol});
                    }
                }
            }

            if (rotten) {
                count++;
            }
        }

        if (fresh > 0) {
            return -1;
        }

        return count;
    }
};