class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();

//         int count = 0;
//         int mod = 1e9 + 7;
//         vector<int>prefix(n , 0);
//         prefix[0] = arr[0];
//         for(int i =1; i<n; i++){
//             prefix[i] = prefix[i-1] + arr[i];
//         }
//            for(int i=0; i<n; i++){

//            for(int j =i; j<n; j++){

//             if( i == 0 ){

//                 if(prefix[j] % 2 !=0 ){
//                     count++;
//                 }

//             }else if( i == j){
//                   if(arr[i] % 2 != 0){
//                     count++;
//                   }

//             }
//             else{
//                 if((prefix[j] - prefix[i-1] ) % 2  != 0 ){
//                     count++;

//                 }

//             }


//            }


//            }
// return count %  mod;

               int mod = 1e9 + 7;
            long long even = 1;
            long long odd = 0;
            long long sum = 0;
            long long ans = 0;





             for(int i=0; i<n; i++){

                  sum += arr[i];

                  if(sum % 2  == 0){
                    ans += odd;
                    even++;
                  }else{
                  
                     ans += even;
                     odd++;



                  }




             }








return ans % mod;
     








        
    }
};