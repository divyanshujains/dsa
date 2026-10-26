class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, long long& sum) {

        int row = grid.size();
        int col = grid[0].size();

         if(i < 0 || i>= row || j< 0 || j>= col || grid[i][j] == 0){
            return;
         }

         sum += grid[i][j];
         grid[i][j] = 0;

        dfs(grid, i + 1, j, sum);
        dfs(grid, i - 1, j, sum);
        dfs(grid, i, j - 1, sum);
        dfs(grid, i , j+1, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] != 0) {
                    long long sum = 0;

                    dfs(grid, i, j, sum);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};