Q - 977. Squares of a Sorted Array 

Code: 
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& A) {
//         vector<int> res(A.size());
//         int l = 0, r = A.size() - 1;
//         for (int k = A.size() - 1; k >= 0; k--) {
//             if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
//             else res[k] = A[l] * A[l++];
//         }
//         return res;
//     }
// };
// 		class Solution {
// 		public:
// 		vector<int> sortedSquares(vector<int>& A) {
//         for(int i=0;i<A.size();i++){
//             A[i]*=A[i];
//         }
     
//         sort(A.begin(),A.end());
        
//         return A;
//     }
//         };
class Solution {

public:    
    vector<int> sortedSquares(vector<int>& A) {  
        
        int l=A.size(),j=l-1;
        
        vector<int> result;
        
        //geting the index of first non negative number
        for(int m=0;m<l;m++){
            if(A[m]>=0){
                j=m;break;
            }
        }
              
        //squaring the elements.
        for(int i=0;i<l;i++)
        {
            A[i]*=A[i];
            
        }
        int k=j,i=j-1;
        //merging the elements such that they are increasing order.
           while(i>=0 && k<l){
               if(A[i]<A[k]){
                   result.push_back(A[i]);
                   i--;
               }
               else{
                   result.push_back(A[k]);
                   k++;
               }
           }
            //copy rest of elemets to result
            while(i>=0){
                result.push_back(A[i]);i--;
            }
            while(k<l){
                result.push_back(A[k]);k++;
            }
            return result ;
    }
};


Code2: using two pointer approch: 

class Solution{
public: 
vector<int> sortedSquares(vector<int>& nums) {

    vector<int> res(nums.size()); 

    int l = 0, r = nums.size()-1; 

    for(int i = nums.size()-1; i>=0; i--){
    
        if(abs(nums[l]) > nums[r] ){
        res[i] = nums[l]*nums[l];
        l++;
        }
    
        else{
        res[i] = nums[r]*nums[r];
        r--;
    }
}
return res;
    }
}; 


