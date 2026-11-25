class Solution {
public:
    double power(double x, long long n) {

        if (n == 0) {
            return 1;
        }
     // linear m time complexity aaagyi thi;
        double ans = power(x, n / 2);

         ans = ans * ans;

         
        if (n % 2 == 1) {
            ans = ans * x;
        }

        return ans;
         

    }

    double myPow(double x, int n) {

        
        long long num = n;

        if (num < 0) {
            double ans = power(x, -num);
            return 1 / ans;
        }

        return power(x, num);

     
    }
};