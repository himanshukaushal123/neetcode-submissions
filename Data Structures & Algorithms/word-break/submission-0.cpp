class Solution {
public:
    bool solve(int i, string& s, vector<string>& wordDict,
               vector<int>& dp) {
        if (i == s.size()) return true;

        if (dp[i] != -1) return dp[i];

        for (string& word : wordDict) {
            int len = word.size();

            if (s.substr(i, len) == word) {
                if (solve(i + len, s, wordDict, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, wordDict, dp);
    }
};