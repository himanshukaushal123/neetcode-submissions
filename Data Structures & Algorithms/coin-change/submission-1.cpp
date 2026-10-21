class Solution {
public:
    int solve(int i, int target, vector<int>& coins, int n,vector<vector<int>>&dp) {
        if (target == 0) return 0;
        if (i == n) return 1e9;
        if(dp[i][target]!=-1)return dp[i][target];
        int take = 1e9;
        if (coins[i] <= target) {
            take = 1 + solve(i, target - coins[i], coins, n, dp);
        }

        int notTake = solve(i + 1, target, coins, n, dp);

        return dp[i][target]=min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(0, amount, coins, coins.size(),dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
