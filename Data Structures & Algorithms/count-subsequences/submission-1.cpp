class Solution {
public:
    int solve(int i,int j,string s,string t,int n,int m,string temp,vector<vector<int>>&dp){
        if(j==m)return 1;
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
            temp+=s[i];
            take=solve(i+1,j+1,s,t,n,m,temp,dp);
            temp.pop_back();
        }
        int not_take=solve(i+1,j,s,t,n,m,temp,dp);
        return dp[i][j]=take+not_take;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t,s.size(),t.size(),"",dp);
    }
};
