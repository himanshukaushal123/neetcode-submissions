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
        solve(nums,i+1,n,temp);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        return solve(nums,0,nums.size(),temp);
    }
};
