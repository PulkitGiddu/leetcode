Q - paindrome checker 
Using recursion method 

Code: 
class Solution{
    public: 
    bool palindromeChecker(vector<int>a, int index, int k){
    if(index > k) return true;
    if(a[index] != a[k]) return false;
    else return palindromeChecker(a, index+1, k-1);
    }
    bool isPalindrome(int x){
        if(x<0) return false;
        vector<int> arr;
        int index = 0; 
        int res = 0;
        while(x != 0){
            res = x%10;
            arr.push_back(res);
            x = x/10; 
        }
        int k = arr.size()-1;
        return palindromeChecker(arr, index, k );

    }
};
