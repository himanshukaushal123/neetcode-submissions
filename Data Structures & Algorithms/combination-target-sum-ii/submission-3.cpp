class Solution {
public:


//                               []
            //                 target=8
            //                /        \
            //            PICK 1      SKIP 1s
            //              [1]          []
            //            t=7          t=8
            //           /   \           \
            //      PICK 1   SKIP 1s      PICK 2
            //       [1,1]    [1]          [2]
            //        t=6      t=7          t=6
            //       /   \       \          / \
            //  PICK 6   ...      PICK 7  PICK 5 PICK 6
            //  [1,1,6]           [1,7]   [2,5]  [2,6]
            //     t=0              t=0     t=3    t=0
            //      ✅                ✅       ❌     ✅
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