class Solution {
public:
    int solve(int i,int j,string s,string t,int n,int m,vector<vector<int>>&dp){
        if(j==m)return 1;
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1,j+1,s,t,n,m,dp);
        }
        int not_take=solve(i+1,j,s,t,n,m,dp);
        return dp[i][j]=take+not_take;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        // return solve(0,0,s,t,s.size(),t.size(),dp);
        int n=s.size();
        int m=t.size();
        // Base case
        for(int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int take=0;
                if(s[i]==t[j]){
                    take=dp[i+1][j+1];
                }
                int not_take=dp[i+1][j];
                dp[i][j]=take+not_take;
            }
        }
        return dp[0][0];
    }
};
