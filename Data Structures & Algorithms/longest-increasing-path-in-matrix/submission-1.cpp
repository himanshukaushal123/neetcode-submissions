class Solution {
public:
    int solve(int n, int m, int i, int j,
              vector<vector<int>>& matrix,vector<vector<int>>&dp) {

        int right = 0, left = 0, up = 0, down = 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // Right
        if(j+1 < m && matrix[i][j+1] > matrix[i][j])
            right = solve(n, m, i, j+1, matrix,dp);

        // Left
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j])
            left = solve(n, m, i, j-1, matrix,dp);

        // Up
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j])
            up = solve(n, m, i-1, j, matrix, dp);

        // Down
        if(i+1 < n && matrix[i+1][j] > matrix[i][j])
            down = solve(n, m, i+1, j, matrix,dp);

        return dp[i][j]=1 + max({right, left, up, down});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(n, m, i, j, matrix,dp));
            }
        }

        return ans;
    }
};