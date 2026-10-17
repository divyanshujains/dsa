class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =  nums.size();
        

        int maxi = INT_MIN;
        int mini = INT_MAX;
        unordered_set<int>mp;


        for(int i : nums){
            
            maxi = max(i , maxi);
            mini = min(i , mini);
           mp.insert(i);

        }
        vector<int>ans;

        for(int j= mini; j<=maxi; j++){

            if(!mp.count(j)){

                ans.push_back(j);
            }




        }
      

  

return ans;


    }
};