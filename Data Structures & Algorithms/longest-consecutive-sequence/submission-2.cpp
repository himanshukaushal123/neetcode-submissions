class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ump;
        int max_con = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Ignore duplicates
            if (ump.find(nums[i]) != ump.end())
                continue;

            int left = 0, right = 0;

            // Check previous number
            if (ump.find(nums[i] - 1) != ump.end())
                left = ump[nums[i] - 1];

            // Check next number
            if (ump.find(nums[i] + 1) != ump.end())
                right = ump[nums[i] + 1];

            int len = left + 1 + right;

            ump[nums[i]] = len;

            // Update left boundary
            if (left > 0)
                ump[nums[i] - left] = len;

            // Update right boundary
            if (right > 0)
                ump[nums[i] + right] = len;

            max_con = max(max_con, len);
        }

        return max_con;
    }
};
