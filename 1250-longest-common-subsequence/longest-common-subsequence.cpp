class Solution {
public:
    //        vector<vector<int>> dp;

    //    int lcs(int i , int j, string text1, string text2 ){

    //             if( i< 0 || j < 0){
    //                 return 0;
    //             }

    //             if(dp[i][j] != -1){
    //                 return dp[i][j];
    //             }

    //            int ans = 0;

    //          if(text1[i] == text2[j]){

    //           ans = 1 + lcs(i-1 , j-1 ,text1 , text2);

    //          }else{

    //              ans = max(lcs(i-1 , j, text1 , text2),  lcs(i , j-1 , text1
    //              , text2));

    //          }

    //      return dp[i][j] = ans;

    //    }

    int longestCommonSubsequence(string text1, string text2) {
        ///////////////////////////////////TLE
        int n1 = text1.size();
        int n2 = text2.size();

        //   dp.assign(n1, vector<int>(n2, -1));
        //          return   lcs(n1-1 , n2-1 , text1 , text2);

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for (int i = 1; i <= n1; i++) {

            for (int j = 1; j <= n2; j++) {

                if (text1[i - 1] == text2[j - 1]) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{


                        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);



                }











            }
        }



      return dp[n1][n2] ; 

    }
};