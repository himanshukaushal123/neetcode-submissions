class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, int n, int m,vector<vector<int>>&dp) {
        if(i==n)return m-j;
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j]=solve(i+1, j+1, s1, s2, n, m,dp);
        }
        int insert= 1+solve(i,j+1,s1,s2,n,m,dp);
        int replace=1+solve(i+1,j+1,s1,s2,n,m,dp);
        int del=1+solve(i+1,j,s1,s2,n,m,dp);

        return dp[i][j]=min({insert,replace,del});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(0, 0, word1, word2, n, m,dp);
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n){
                    dp[i][j]=m-j;
                }else{
                    if(j==m){
                        dp[i][j]=n-i;
                    }else{
                        if(word1[i] == word2[j]){
                            dp[i][j]=dp[i+1][j+1];
                        }else{
                                int insert= 1+dp[i][j+1];
                                int replace=1+dp[i+1][j+1];
                                int del=1+dp[i+1][j];
                                dp[i][j]=min({insert,replace,del});
                        }
                    }
                }
            }
        }
        return dp[0][0];
    }
};