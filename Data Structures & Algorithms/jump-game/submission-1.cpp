class Solution {
public:
    bool solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n-1)return true;
        if(nums[i]==0){
            return dp[i]=false;
        }
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
        if(solve(i+j,n,nums,dp)){
            return dp[i]=true;
        }
        }
        return dp[i]=false;

    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums.size(),nums,dp);
    }
};
