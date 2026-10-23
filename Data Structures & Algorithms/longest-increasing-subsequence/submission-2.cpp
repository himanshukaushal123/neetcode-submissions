class Solution {
public:
// poit to remeber--> how last element handles(last_element+1) 
    int solve(int i, vector<int>&nums, int last_ele,int n,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][last_ele+1]!=INT_MIN)return dp[i][last_ele+1];
        int take=0;
        if(last_ele == -1 || nums[i]>nums[last_ele]){
            take=1+solve(i+1,nums,i,n,dp);
        }
        int not_take=solve(i+1,nums,last_ele,n,dp);
        return dp[i][last_ele+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,INT_MIN));
        return solve(0,nums,-1,n,dp);
    }
};
