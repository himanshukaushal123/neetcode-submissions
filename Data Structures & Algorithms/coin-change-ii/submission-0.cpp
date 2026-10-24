class Solution {
public:
    int count=0;
    int solve(int i,vector<int>&coins,int target,int n,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(i==n)return 0;
        if(dp[i][target]!=-1)return dp[i][target];
        int take=0;
        if(coins[i]<=target){
            take=solve(i,coins,target-coins[i],n,dp);
        }
        int not_take=solve(i+1,coins,target,n,dp);
        return dp[i][target]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,coins,amount,coins.size(),dp);
    }
};
