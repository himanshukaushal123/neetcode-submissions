class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=0,down=0;
        if(i+1<n)up=solve(i+1,j,n,m,dp);
        if(j+1<m)down=solve(i,j+1,n,m,dp);
        return  dp[i][j]=up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};
