class Solution {
public:




    vector<int> getStrongest(vector<int>& arr, int k) {
       
       int n  = arr.size();
        sort(arr.begin() , arr.end());

        int m = arr[(n-1)/2];

        vector<pair<int , int>>v;


         for (int x : arr) {
            v.push_back({abs(x - m), x});
        }


           sort(v.begin(), v.end(), greater<pair<int, int>>());
  


          vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;


        
        




        




        
        
    }
};