class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

         priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int ,int>>>pq;

              for(int i=0; i<points.size(); i++){
                 
                 int x =  points[i][0];
                 int y = points[i][1];

                 int dis = ( x * x) + (y * y);
                   
                   pq.push({dis ,i});

              }


   vector<vector<int>>ans;
        
              for(int i=0; i< k; i++){
               
               auto it = pq.top();
               pq.pop();

               int index = it.second;

              ans.push_back(points[index]);



              }


return ans;

        
    }
};