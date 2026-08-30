class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy_strs = strs;
        int n = strs.size();

        for (int i = 0; i < n; i++) {
            sort(strs[i].begin(), strs[i].end());
        }

        unordered_map<string, vector<string>> ump;

        for (int i = 0; i < n; i++) {
            ump[strs[i]].push_back(copy_strs[i]);
        }

        vector<vector<string>> ans;

        for (auto& val : ump) {
            ans.push_back(val.second);
        }

        return ans;
    }
};
