class Solution {
public:
    double findMedianSortedArrays(vector<int>& A,vector<int>& B) {
        // Always binary search on smaller array
        if (A.size() > B.size()) {
            swap(A, B);
        }

        int m = A.size();
        int n = B.size();

        int left = 0;
        int right = m;

        int leftSize = (m + n + 1) / 2;

        while (left <= right) {

            int i = left + (right - left) / 2;

            int j = leftSize - i;

            int A_left  = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];

            int B_left  = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];

            // Correct partition
            if (A_left <= B_right &&
                B_left <= A_right) {

                // Odd
                if ((m + n) % 2 == 1) {
                    return max(A_left, B_left);
                }

                // Even
                return (max(A_left, B_left)
                    + min(A_right, B_right)) / 2.0;
            }

            // Move partition in A to the right
            else if (A_left > B_right) {
                right = i - 1;
            }

            // Move partition in A to the left/right?
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};
