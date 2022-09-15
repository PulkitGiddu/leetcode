Q - 119. Pascal's Triangle II
/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
*/
  
Code: 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1}; // Base Case

        vector<int> currentRow = {1}; // current row with 1 value in it
        vector<int> previousRow = getRow(rowIndex-1); // get the previous row

        // Now fill the current row based on previous row
        for(int i=1;i<rowIndex;i++){
            currentRow.push_back(previousRow[i-1]+previousRow[i]);
        }

        currentRow.push_back(1); // fill the last element of current row
        return currentRow;
    }
};
