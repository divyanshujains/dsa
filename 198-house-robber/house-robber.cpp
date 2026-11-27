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

   int ml2 (vector<int>& nums , vector<int>& ndp , int i){

       if(i < 1){
        return 0;

       }

       if(i == 1){
        return nums[1];
       }

       if(i == 2){
        return max(nums[1] , nums[2]);
       }
       
       if (ndp[i] != -1) {
            return ndp[i];
        }

        if (ndp[i] != -1) {
            return ndp[i];
        }

         int ans = max(ml(nums , ndp ,i-1 ) , nums[i] + ml(nums , ndp , i-2));


      ndp[i] = ans;

   return ans;


   }


    int rob(vector<int>& nums) {

 int n = nums.size();

 vector<int>dp(n , -1);

  int one  = ml(nums , dp , n-2);
       vector<int>ndp(n , -1);
  int two = ml(nums , ndp , n-1);

  return max(one ,two);




    }
};