class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int total_row=matrix.size();
        int total_col=matrix[0].size();

        int left=0;
        int right=total_col*total_row-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            // convert 1d corrds-->2d coords
            int row=mid/total_col;
            int col=mid%total_col;

            if(matrix[row][col]==target)return true;
            if(matrix[row][col]>target){
               right=mid-1;
            }else{
               left=mid+1;
            }

        }
        return false;
    }
};