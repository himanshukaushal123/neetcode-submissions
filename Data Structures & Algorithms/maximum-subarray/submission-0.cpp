class Solution {
public:
    int solve(int i, int n, vector<int>& nums,vector<int>&dp) {

        if (i == n)
            return 0;
        if(dp[i]!=INT_MAX)return dp[i];
        int sum = nums[i] + solve(i + 1, n, nums,dp);

        return dp[i]=max(nums[i], sum);
    }

    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN;
        vector<int>dp(nums.size(),INT_MAX);
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, solve(i, nums.size(), nums,dp));
        }

        return ans;
    }
};