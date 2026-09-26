class Solution {
public:
//                                       []
    //                           used = [F,F,F]
    //                           /       |       \
    //                        PICK1    PICK2    PICK3
    //                          |        |        |
    //                         [1]      [2]      [3]
    //                        /  \      /  \      /  \
    //                       2    3    1    3    1    2
    //                      /      \  /      \  /      \
    //                   [1,2]   [1,3][2,1][2,3][3,1][3,2]
    //                     |       |    |     |    |     |
    //                     3       2    3     1    2     1
    //                     |       |    |     |    |     |
    //                   [123]   [132][213] [231][312] [321]
    //                     ✅      ✅    ✅     ✅    ✅    ✅
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int i,int n,vector<int>&temp,vector<bool>&used){
        if(temp.size() == n){ans.push_back(temp);return;}
        if(i == n) return;
        //pick
        if(!used[i]){
            used[i]=true;
            temp.push_back(nums[i]);
            solve(nums,0,n,temp,used);
            //not pick
            temp.pop_back();
            used[i]=false;
        }
        solve(nums,i+1,n,temp,used);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool>used(nums.size(),false);
        solve(nums,0,nums.size(),temp,used);
        return ans;
        
    }
};
