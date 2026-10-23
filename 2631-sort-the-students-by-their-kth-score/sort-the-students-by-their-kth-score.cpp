class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        int m = score.size();
        int n = score[0].size();

        vector<pair<int , int>>v;

           for(int i = 0; i<m; i++){
           v.push_back({score[i][k], (-1 * i)});
           }

           sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
});

           vector<int>newrow;

           for(int i=0; i<v.size(); i++){

            newrow.push_back(-1 * v[i].second);

           }

           vector<vector<int>>ans;


           for(int i=0; i<newrow.size(); i++){
            vector<int>row;

            for(int j = 0; j<n; j++){

                row.push_back(score [newrow[i]][j]);


            }

            ans.push_back(row);

           }








return ans;



      
        
    }
};