class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> solve(vector<int>& nums,int i,int n,vector<int>temp){
        if(i==n){ans.push_back(temp);return ans;}
        //pick
        temp.push_back(nums[i]);
        solve(nums,i+1,n,temp);
        //not pick
        temp.pop_back();
        // Skip duplicate for the not-pick branch
        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(nums,i+1,n,temp);
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        return solve(nums,0,nums.size(),temp);
    }
};
