class Solution {
public:

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(string& s,
               int start,
               int end,
               vector<string>& temp,
               vector<vector<string>>& ans) {

        // We have partitioned the entire string
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        // End went outside the string
        if (end == s.size())
            return;

        // PICK
        if (isPalindrome(s, start, end)) {

            temp.push_back(s.substr(start, end - start + 1));

            // Start partitioning after the selected substring
            solve(s, end + 1, end + 1, temp, ans);

            temp.pop_back();
        }

        // NOT PICK
        // Extend the current substring
        solve(s, start, end + 1, temp, ans);
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, 0, temp, ans);

        return ans;
    }
};