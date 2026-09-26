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

        // No more elements or target cannot be achieved
        if (i == n || target < 0) {
            return;
        }

        // PICK
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);

            solve(candidates, i + 1, n,
                  target - candidates[i], temp);

            temp.pop_back();
        }

        // NOT PICK
        // Skip all duplicates of candidates[i]
        int next = i + 1;

        while (next < n && candidates[next] == candidates[i]) {
            next++;
        }

        solve(candidates, next, n, target, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, 0, candidates.size(), target, temp);

        return ans;
    }
};