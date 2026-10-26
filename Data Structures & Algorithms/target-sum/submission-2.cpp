class Solution {
public:
    int solve(int i,vector<int>&nums,int target,int n,vector<vector<int>>&dp){
        if(i==n){
            if(target==0)return 1;
            else return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int take=0;
        if(nums[i]<=target){
            take=solve(i+1,nums,target-nums[i],n,dp);
        }
        int not_take=solve(i+1,nums,target,n,dp);
        return dp[i][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //s1-s2=target
        //s1+s2=total_sum
        //s1=(taget+total_sum)/2;
        int n=nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(abs(target)>abs(total_sum))return 0;
        if((target+total_sum)%2!=0)return 0;
        int new_target=(target+total_sum)/2;
        vector<vector<int>>dp(n,vector<int>(new_target+1,-1));
        return solve(0,nums,new_target,n,dp);
    }
};
