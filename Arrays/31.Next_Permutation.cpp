//Approch 1:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1){
            return;
        }
        
        int idx1;
        for (int i = nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }
        }
        
        if(idx1<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int idx2=0;
            for(int i = nums.size()-1; i>=0; i--){
                if(nums[i] > nums[idx1]){
                    idx2 = i;
                    break;
                }
            }
            
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+idx1+1, nums.end());
        }
        
    }
};

//Approch 2:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size(), k, l;
        for (k = n - 2; k>=0; k--){
            if (nums[k] < nums[k+1]){
                break;
            }
        }
        if (k<0){
            reverse(nums.begin(), nums.end());
        } 
        else{
            for(l = n - 1; l > k; l--){
                if (nums[l] > nums[k]){
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
        
};
