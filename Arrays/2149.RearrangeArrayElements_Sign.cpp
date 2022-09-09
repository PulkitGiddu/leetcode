// 2149. Rearrange Array Elements by Sign
code: 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
    int n=nums.size(); // First we are checking the lenght of the given array
        
    vector<int> v(n); // also we have created one array to store +ve and -ve elements
     
    int positive = 0;    
    int negative = 1;
    
        for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            v[positive]=nums[i]; 
            positive+=2; // now for every +ve element we will be moving its position to +2 
        }
        else{
            v[negative]=nums[i];
            negative+=2; //// now for every -ve element we will be moving its position to +2
        }   
    }
    return v;
}
};
