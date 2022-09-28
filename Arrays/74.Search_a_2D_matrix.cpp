74. Search a 2D matrix:
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
code: 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // so we have sorted elements in matrix for that we can place that in linear mode 
        //[1, 3, 5, 7 , 10, 11, 16, 20, 23, 30, 34, 60]
        // 3 * 4 - 1 = 12 - 1 = 11 
        int start = 0;
        int end = row * col - 1;
        int mid = start + (mid - start)/2;
        
        while(start <= end){
            // here we were searching for the elements into the row , col.
            int element = matrix[mid/col][mid%col];
            
            if(element == target){
                return 1;
            }
            if( element < target){
                // move into right part 
                start = mid + 1;
            }
            else{
                // move into left part
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return 0;
    }
};

//Time complexity: O(log(row*col)) or O(log(n*m))
