1539. Kth Missing Positive Number 

CodE:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k < arr[0]){
            return k;
        }
        int low = 0; 
        int high = arr.size();
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] - mid - 1 < k){
                low = mid + 1;
            }
            else{
                high = mid;
        }
            }
        return low + k;
      
    }
};
