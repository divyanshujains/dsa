class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<vector<pair<int , int>>>adj(n+1);

        for(auto it : times){
            //u = parent;
            int u = it[0];
            //v = child
            int v = it[1];
            // time between u and v
            int dist = it[2];
            //now push the child in parent;
            adj[u].push_back({v , dist}); 

        }
           
           priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int ,int>>>pq;
            vector<int>distance(n+1, INT_MAX);

           pq.push({0 , k});

           distance[k] = 0;

           while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
             
            int node = it.second;
            int dis =  it.first;

            if(distance[node] < dis){
                continue;
            }

         
            for(auto iter: adj[node]){

                int neg = iter.first;
                int d = iter.second;

                if(d + dis < distance[neg]){

                  distance[neg] = d + dis;

                  pq.push({d+dis , neg});

                }


            }

        


           } 



           int ans = 0;
for(int i = 1; i <= n; i++) {

    if(distance[i] == INT_MAX) {
        return -1;
    }

    ans = max(ans, distance[i]);
}
      return ans;


        
    }
};