class Solution {
public:
    int solve(int i, vector<int>& cost, int n, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int one_step = cost[i] + solve(i + 1, cost, n, dp);
        int two_step = cost[i] + solve(i + 2, cost, n, dp);

        return dp[i] = min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(solve(0, cost, n, dp),
                   solve(1, cost, n, dp));
    }
};