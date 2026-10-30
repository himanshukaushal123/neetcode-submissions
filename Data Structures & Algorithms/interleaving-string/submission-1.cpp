class Solution {
public:
    bool solve(string s1,string s2,string s3,int p1,int p2,int p3,int n,int m,int l,vector<vector<vector<int>>>&dp){
        if(p3==l){
            if(p1==n && p2==m)return dp[p1][p2][p3]=true;
            return dp[p1][p2][p3]=false;
        } 
        if(dp[p1][p2][p3]!=-1)return dp[p1][p2][p3];
        if(p1<n && s1[p1]==s3[p3]){
            if(solve(s1,s2,s3,p1+1,p2,p3+1,n,m,l,dp))return dp[p1][p2][p3]=true;
        }
        if(p2<m && s2[p2]==s3[p3]){
            if(solve(s1,s2,s3,p1,p2+1,p3+1,n,m,l,dp))return dp[p1][p2][p3]=true;
        }
        return dp[p1][p2][p3]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),l=s3.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1, -1)));
        if(s1.size()+s2.size() != s3.size())return false;
        return solve(s1,s2,s3,0,0,0,s1.size(),s2.size(),s3.size(),dp);
    }
};
