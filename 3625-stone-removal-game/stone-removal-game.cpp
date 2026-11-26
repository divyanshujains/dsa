class Solution {
public:
    bool canAliceWin(int n) {
      int stones = n;
      int ans = false;
         
         for(int i=10; i>=0; i--){

              if(stones >= i){
                stones = stones - i;
              }else{
                    
                    if(i % 2 == 0){
                         ans = false;
                    }else{
                        ans = true;
                    }

                      break;

              }




         }


return ans;

        
    }
};