
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        // {effort, row, col} 
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({0, 0, 0});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = get<0>(it);
            int row = get<1>(it);
            int col = get<2>(it);

            //agar pehle se dist me acha ans hai toh hum kuch  nhi kareneg;

            if (effort > dist[row][col]) {
                continue;
            }

            if (row == n - 1 && col == m - 1) {
                return effort;
            }
            // charo direction travel karenge 

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {

                    int diff = abs(
                        heights[nr][nc] - heights[row][col]
                    );

                    // likin likhnge wahi jo abhi tak max hai na ki abhi jo value ayi hai

                    int newEffort = max(effort, diff);

                    if (newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};
