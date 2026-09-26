class Solution {
public:
// nums = [2,3,6,7]
// target = 7
//                          [] (target=7)
 //                       /             \
            //         TAKE 2           SKIP 2
            //           [2]             []
            //         /     \          /    \
            //   TAKE 2     SKIP 2   TAKE 3  SKIP 3
            //    [2,2]       [2]      [3]      []
            //      |           |        |        |
            //   TAKE 2       TAKE 3  TAKE 3    TAKE 6...
            //   [2,2,2]      [2,3]    [3,3]
            //      |           |        |
            //   target 1     target 2  target 1
            //      |           |        |
            //    STOP        STOP      STOP
            // n = number of elements in nums
// T = target
// m = minimum value in nums
// Time Complexity

// A rough upper bound is:

// O(n^(T/m))

// Why?

// The maximum depth of the recursion is approximately:

// T / m

// because the smallest number can be chosen repeatedly.

// At each level, we can potentially explore up to n choices.

// So:

// Depth ≈ T/m
// Branching ≈ n

// => O(n^(T/m))
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
