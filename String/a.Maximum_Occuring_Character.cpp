// Q- Maximum Occuring character. GFG 
/*
Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
Example 2:

Input:
str = output
Output: t
Explanation:  t and u are the characters
with the same frequency, but t is
*/
  
code: 
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
         int arr[26] = {0};
    //create an array of count of characters
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
        int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans;
    }
    

};
