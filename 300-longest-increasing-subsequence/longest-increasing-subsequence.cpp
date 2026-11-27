
class Solution {
public:

    int lis(vector<int>& nums, int idx, vector<int>& dp) {

        if (dp[idx] != -1) return dp[idx];

        int ans = 1;

        for (int i = 0; i < idx; i++) {

            if (nums[idx] > nums[i]) {
                ans = max(ans, 1 + lis(nums, i, dp));
            }
        }

        return dp[idx] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, lis(nums, i, dp));
        }

        return ans;
    }
};
