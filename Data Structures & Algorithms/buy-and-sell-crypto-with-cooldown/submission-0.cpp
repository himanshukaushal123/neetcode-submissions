class Solution {
public:
    int solve(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int n){
        if(i>=n)return 0;
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            profit=max(-prices[i]+solve(i+1,0,prices,dp,n),solve(i+1,1,prices,dp,n));
        }else{
            profit=max(prices[i]+solve(i+2,1,prices,dp,n),solve(i+1,0,prices,dp,n));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,n);
    }
};
