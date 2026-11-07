class Solution {
public:
   
   int ml(vector<int>& nums , vector<int>& dp , int i){


    if(i == 0){
        return nums[0];
    }
    if(i == 1){
        return max(nums[0] , nums[1]);
    }

    if( i < 0){
        return 0;
    }

        if (dp[i] != -1) {
            return dp[i];
        }
    int ans = max(ml(nums , dp ,i-1 ) , nums[i] + ml(nums , dp , i-2));

    dp[i] = ans;

   return ans;

   }


    int rob(vector<int>& nums) {

 int n = nums.size();

    vector<int>dp(n , -1);

  return ml(nums , dp , n-1);




    }
};