class Solution {
public:
    int solve(int i, int n, vector<int>& nums,vector<int>&dp) {

        if (i >= n - 1)
            return 0;

        if (nums[i] == 0)
            return INT_MAX;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {

            int next = solve(i + j, n, nums,dp);
            // to avoid interoverflow
            if (next != INT_MAX) {
                ans = min(ans, 1+next);
            }
        }

        return dp[i]=ans;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0, nums.size(), nums,dp);
    }
};