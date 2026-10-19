class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=0)return dp[n];
        if (n == 0 || n == 1) {
            return 1;
        }
        int one_step=solve(n-1,dp);
        int two_step=solve(n-2,dp);
        return dp[n]=one_step+two_step;
    }
    int climbStairs(int n) {
     vector<int>dp(n+1,0) ;
     return solve(n,dp) ; 
    }
};
