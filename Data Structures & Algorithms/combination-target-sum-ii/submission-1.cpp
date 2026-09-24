class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int i, int n,
               int target, vector<int>& temp) {

        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(candidates[j]>target)break;
            if(j>i && candidates[j]==candidates[j-1])continue;
            temp.push_back(candidates[j]);

            solve(candidates, j + 1, n,
                  target - candidates[j], temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, 0, candidates.size(), target, temp);

        return ans;
    }
};