//Set matrix zero problem in which Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do all that in place.
/*
So approch in which we can solve this problem is brute force approch 
This is our first approch to problem.
So in this our approch will be like we have to triverse the elements 
where ever we find 0 so what we do we will put -1 in that coloum as well as in that row 
after this convert all the -1 to 0 and in this way our (2 * 2) matrix will be all 0 
time complexicty will be (N * M) for linearly triversing the array for every triversal and for every triversal in row as well as in coloum that will tke (N + M) time.

So if we optimize this problem
for that we will take two arrays and triverse the elements 
time complexicity will be 2 * (N * M)
and space complxicity will be O(n) because we did change in the same matrix that we have 

Test case:
1. Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
   Output: [[1,0,1],[0,0,0],[1,0,1]]
   
2. Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
   Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]   
*/

//Code:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        if(n == 0) return;
        
        /*
        matrix[0][0] indicates the first row should be zero out,
        so we need this variable whether first col should be zero out or not
        */
        bool firstCol = false;
        
        for(int i = 0; i < m; ++i){
            //special case: first column
            if(matrix[i][0] == 0){
                firstCol = true;
            }
            
            //for 2nd and later columns, we use the first row as indicator
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        /*
        note that i starts from 1!
        we zero out the part right and down to matrix[1][1](included) first
        */
        for(int i = 1; i < m; ++i){
            if(matrix[i][0] == 0){
                //j starts from 1
                for(int j = 1; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //j starts from 1
        for(int j = 1; j < n; ++j){
            if(matrix[0][j] == 0){
                //i starts from 1
                for(int i = 1; i < m; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "===================" << endl;
        
        /*
        finally zero out the first row
        */
        if(matrix[0][0] == 0){
            for(int j = 1; j < n; ++j){
                matrix[0][j] = 0;
            }
        }
        
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "===================" << endl;
        
        /*
        finally zero out the first col
        */
        if(firstCol){
            //i starts from 0
            for(int i = 0; i < m; ++i){
                matrix[i][0] = 0;
            }
        }
        
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "===================" << endl;
    }
};

