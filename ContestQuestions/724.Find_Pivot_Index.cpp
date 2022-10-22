Q - 724. Find Pivot Index 
Code: 
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
    
//         int n = nums.size(); 
//         for(int i = 1; i<n; i++){                // -------> n 
            
//             int leftSum = 0;
//             // So we were checking into left part of the ith position
//             for( int j = i - 1; j>=0; j --){
//                 leftSum += nums[j]; // we are adding the sum of all leftmost elements
//             }

//             int rightSum = 0;
//             for( int k = i + 1; k<n; k++ ){     // --------> n
//                 rightSum += nums[k];
//             }

//             if( leftSum == rightSum){
//                 return i;                       
//             }
//         }
//         return -1;                             //// T.C = O(N*2)
//     }                                          // S.C = O(1) we are using variables only. 
// };

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int allsum = accumulate(nums.begin(), nums.end(), 0);
//         int cumsum = 0;
        
//         for(int i = 0; i < nums.size(); i++){
//             if(cumsum*2 == (allsum-nums[i])){
//                 return i;
//             }
//             cumsum += nums[i];
//         }
        
//         return -1;
//     }
// };
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    // Efficient Solution Time O(N) & Auxiliary Space O(1)
    // Create a sum array in which each element stores 
    // the sum of elements of nums vector up to that index.
    // Calculate left & right sum. For example-
    // nums[]=[1,7,3,6,5,6]
    // sum[]= [1,8,11,17,22,28]
    // left[3]=17-6=11
    // right[3]=28-17=11
    // return 3
    int len=nums.size();
    if(len==1)
        return 0;
    int sum[len];
    sum[0]=nums[0];
    for(int i=1;i<len;i++){
        sum[i]=nums[i]+sum[i-1];
    }
    for(int i=0;i<len;i++)
    {
        int left=sum[i]-nums[i];
        int right=sum[len-1]-sum[i];
            
    if(left==right)
        return i;
    }
      return -1;
    }
};
