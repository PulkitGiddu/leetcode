48. Rotate Image : 
/*
|1 2 3|       |1 4 7|       |7 4 1|
|4 5 6| ----> |2 5 8| ----> |8 5 2|
|7 8 9|       |3 6 9|       |9 6 3|

first transpose the matrix
then swap ith row with j-1 row 
then  we'll get the 90 degree matrix.

*/
Code:
 void rotate(vector<vector<int>>& matrix) {
		// complement of matrix 
        int n = matrix.size();
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; ++i) {
		// 2 Pointer approach :  just like we do in 1D array we take left and right pointers
		// and swap the values and then make those pointers intersect at some point.
            int left = 0, right = n-1;
            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
    }
