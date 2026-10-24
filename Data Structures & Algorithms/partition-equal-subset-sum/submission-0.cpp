class Solution {
public:
    int total(vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    bool solve(int i,vector<int>&nums,int n,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==n)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        if(nums[i]<=target){
            if(solve(i+1,nums,n,target-nums[i],dp)){
                return dp[i][target]=true;
            }
        }
        if(solve(i+1,nums,n,target,dp)){
            return dp[i][target]=true;
        }
        return dp[i][target]=false;
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = total(nums);
        if(total_sum%2!=0)return false;
        int target=total_sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,nums.size(),target,dp);

    }
};
