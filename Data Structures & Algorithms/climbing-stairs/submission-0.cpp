class Solution {
   public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return check(n, dp);
    }

    int check(int n, vector<int>& dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = check(n - 1, dp) + check(n - 2, dp);
    }
};
