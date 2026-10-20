class Solution {
public:
    int count=0;
    int start=0;
    int maxLen=0;
    void expand(string& s, int left, int right) {
        int n = s.size();

        while (left >= 0 && right < n &&
               s[left] == s[right]) {
            count++;  // Each successful expansion is one palindrome
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();
        start = 0;
        maxLen = 1;

        for (int i = 0; i < n; i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }

        return count;
    }
};
