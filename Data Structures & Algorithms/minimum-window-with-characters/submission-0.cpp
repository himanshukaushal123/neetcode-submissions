class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            have[c]++;

            // This character requirement is now completely satisfied
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            // Window is valid
            while (formed == required) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                have[leftChar]--;

                // Window became invalid
                if (need.count(leftChar) &&
                    have[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
