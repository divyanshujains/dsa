class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

  int n = nums.size();

       
       vector<int>prefix(n , 0);
         
         prefix[0] = nums[0];
  
       for(int i=1; i<n; i++){

          prefix[i] = prefix[i-1] + nums[i];

       }  
     
     int ans = INT_MAX;


        for(int w=l; w<=r; w++){


            int s = 0;
            int e = w-1;

            while(e  < n){

                int num = 0;
                  
                 if(s == 0){

                    num = prefix[e];
                     
                 }else{
                         num = prefix[e] - prefix[s-1];

                 }
         

              if(num  > 0){

                ans = min(num , ans);
                
              }

              s++;
              e++;



            }

             






        }

      

   if(ans == INT_MAX){
    return -1;
   }

   return ans;






    }
};