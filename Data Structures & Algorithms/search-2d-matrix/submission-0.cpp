class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m * n - 1;

        int row = 0, col = 0;

        while(start <= end){
            int mid = start + (end - start) / 2;

             row = mid / n;
             col = mid % n;

            int num = matrix[row][col];

            if(target > num){
                start = mid + 1;
            } else if(num > target){
                end = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
