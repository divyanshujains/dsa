class Solution {
public:
    
    int solve(int n , int idx , vector<int>& cost , vector<int>& dp){

       if(idx >= n){
        return 0;
       }

         if (dp[idx] != -1) {
            return dp[idx];
        }



      int ans =  cost[idx] +  min({solve( n , idx+1 , cost , dp ) , solve(n , idx+2 , cost , dp)});

      return dp[idx] = ans;


    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

         vector<int>dp(n+1 , -1);

       return min(
            solve(n, 0, cost, dp),
            solve(n, 1, cost, dp)
        );
    }
};