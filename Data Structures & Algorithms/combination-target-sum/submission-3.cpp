class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int n,int i,int target,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // pick
        for(int j=i;j<=n-1;j++){
            if(nums[j]>target)break;
            temp.push_back(nums[j]);
            solve(nums,n,j,target-nums[j],temp);
             // Backtrack
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(nums,nums.size(),0,target,temp);
        return ans;
    }
};
