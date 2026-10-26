class Solution {
public:

void dfs(vector<vector<int>>& grid , int i , int j){

   int row = grid.size();
   int col = grid[0].size();
   if( i < 0 || i>=row || j<0 || j>= col || grid[i][j] == 0){
    return;

   }

  

       grid[i][j] = 0;
    

       dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);





}




    int numEnclaves(vector<vector<int>>& grid) {

          int row = grid.size();
          int col = grid[0].size();

          for(int i=0; i<col; i++){

            if(grid[0][i] == 1){
                dfs(grid,0 , i);
            }

            if(grid[row-1][i] == 1){
                dfs(grid , row-1, i);
            }



          }

            
            for(int i=0; i<row; i++){

            if(grid[i][0] == 1){
                dfs(grid,i, 0);
            }

            if(grid[i][col-1] == 1){
                dfs(grid , i, col-1);
            }



          }


  int count = 0;

          for(int i=0; i<row; i++){
               
               for(int j=0; j<col; j++){

                if(grid[i][j] == 1){
                    count++;
                }


               }
        

          }

          




return count;


        
    }
};