class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int currcolor,
             int color) {

        int row = image.size();
        int col = image[0].size();

        if (sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] != currcolor) {
            return;
        }


            image[sr][sc] = color;

            dfs(image, sr + 1, sc, currcolor, color);
            dfs(image, sr - 1, sc, currcolor, color);
            dfs(image, sr, sc - 1, currcolor, color);
            dfs(image, sr, sc + 1, currcolor, color);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] != color) {
            dfs(image, sr, sc, image[sr][sc], color);
        }

        return image;
    }
};