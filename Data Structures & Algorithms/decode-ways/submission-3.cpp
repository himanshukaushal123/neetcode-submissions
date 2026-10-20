class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+2,0);
        // return solve(s,0,s.size(),dp);
        int n=s.size();
        if(n==0)return 0;
        if(s[0]=='0')return 0;
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')continue;
            dp[i]=dp[i+1];

            if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};