class Solution {
public:
    int solve(int i1,int i2,int n,int m,string s1,string s2,vector<vector<int>>&dp){
        if(i1==n || i2==m)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        int take=INT_MIN;
        if(s1[i1]==s2[i2])take=1+solve(i1+1,i2+1,n,m,s1,s2,dp);
        int not_take=max(solve(i1+1,i2,n,m,s1,s2,dp),solve(i1,i2+1,n,m,s1,s2,dp));
        return dp[i1][i2]=max(take,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,text1,text2,dp);
    }
};
