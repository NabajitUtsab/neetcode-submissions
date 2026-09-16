class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        int amount = dfs(n - 1, nums, dp);

        return amount;
    }

    int dfs(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0) {
            return nums[ind];
        }
        if (ind < 0) {
            return 0;
        }

        if (dp[ind] != -1) {
            return dp[ind];
        }

        int pick = nums[ind] + dfs(ind - 2, nums, dp);
        int notPick = 0 + dfs(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }
};
