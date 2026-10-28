class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> ans(row, vector<int>(col, -1));

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

    
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }


        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for (int k = 0; k < 4; k++) {

                int newrow = x + dx[k];
                int newcol = y + dy[k];

                if (newrow < 0 || newrow >= row ||
                    newcol < 0 || newcol >= col) {
                    continue;
                }

             
                if (ans[newrow][newcol] == -1) {

                    ans[newrow][newcol] = ans[x][y] + 1;

                    q.push({newrow, newcol});
                }
            }
        }

        return ans;
    }
};