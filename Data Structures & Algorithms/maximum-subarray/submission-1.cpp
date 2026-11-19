
class Solution {
public:
    int solve(int i, int n, vector<int>& nums,
              vector<int>& dp) {

        if (i == n)
            return 0;

        if (dp[i] != INT_MAX)
            return dp[i];

        int sum = nums[i] + solve(i + 1, n, nums, dp);

        return dp[i] = max(nums[i], sum);
    }

    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;
        int start = 0, end = 0;

        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {

            int curr = solve(i, n, nums, dp);

            if (curr > ans) {
                ans = curr;
                start = i;
            }
        }

        // Find the ending index
        int sum = 0;

        for (int i = start; i < n; i++) {
            sum += nums[i];

            if (sum == ans) {
                end = i;
                break;
            }
        }

        // Print subarray
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }

        return ans;
    }
};
