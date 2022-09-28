Q - 240. search in a 2d array II. 
/*

*/
code:
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int rowIndex = 0;
//         int colIndex = col - 1;
        
//         while(rowIndex >=0 && rowIndex < row && colIndex >= 0 && colIndex >= col){
//             int element = matrix[rowIndex][colIndex];
            
//             if(element == target)
//             {
//                 return 1;   
//             }
//             if (element < target )
//             {
//                 rowIndex++;
//             } 
//             else
//             {
//                 colIndex--;
//             }
//         }
//         return 0;
//     }
// };
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int i = 0;
//         int j = matrix[0].size() - 1;
        
//         while(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()){
//             if(matrix[i][j] == target) return true;
//             else if(matrix[i][j] > target) j--;
//             else if(matrix[i][j] < target) i++;
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int i=0,j=col-1;

        while(j>=0 && i<row){

            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}; 
// time complexity : O(log(m+n))
