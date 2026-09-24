class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums,int i,int n,vector<int>temp){
        // Every temp is a valid subset
        ans.push_back(temp);
        for(int j=i;j<n;j++){
            if(j > i && nums[j]==nums[j-1]){
                continue;
            }
            //pick
            temp.push_back(nums[j]);
            solve(nums,j+1,n,temp);
            //not pick
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(nums,0,nums.size(),temp);
        return ans;
    }
};
