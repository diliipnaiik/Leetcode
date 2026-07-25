class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        int m = matrix.size();

        while(row < m && col != -1 && row != m){
            int current = matrix[row][col];

            if(current == target){
                return true;
            }

            else if(current < target){
                row++;
            }

            else if(current > target){
                col--;
            }
        }
        return false;
    }
};