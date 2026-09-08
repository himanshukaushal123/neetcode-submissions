class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int i = 0;

        while (i < nums.size()) {

            int num = nums[i];

            // Already in correct position
            if (num == i + 1) {
                i++;
            }

            // Same number already exists at its correct position
            else if (nums[num - 1] == num) {
                return num;
            }

            // Put num into its correct position
            else {
                swap(nums[i], nums[num - 1]);
            }
        }

        return -1;
    }


};
