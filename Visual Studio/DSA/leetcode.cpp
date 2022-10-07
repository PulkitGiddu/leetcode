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




//permutation

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



Buy or rent the stock 
{
        int lsf = Integer.MAX_VALUE; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = INT_MAX; 
        int op = 0; //Overall profit 
        int j = 0;  //Profit if we sell that stock today
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < a){
                a = prices[i];
            }
            j = prices[i] - a;
            if(op < j){
                op = j;
            }
        }
        return op;
    }


class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
      unordered_map<int, int> m;
        int sum = 0;
        int n = nums.size();
        int count = 0;
        
        for(int i =0; i<n; i++){
            sum += nums[i];
            if (sum == count) return true;
             
             if(m.find(sum + count) != m.end()){
                nums = m(sum - count) + nums;
             }
              if(m.find(nums) != m.end()){
                m[sum]++ ;
            }
            else {
                m[nums]  = 1;

            }

        }
        return count;
              
        }
    
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> m;
        int count = 0;
        int sum = 0; 
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if (sum == k) count++;
            
            if(m.find(sum - k) != m.end()){
                count   = m[sum -k] + count;
            }
            if(m.find(sum) != m.end()){
                m[sum]++;
            }
            else {
                m[sum]  = 1;

            }

        }
        return count;
            
        
    }
};

//   void sortColors(vector<int>& nums) {
        
//         // initialize variables:
//         int low = 0, mid = 0, high = nums.size() - 1;
        
//         // logic:
//         while(mid <= high)
//         {
//             switch(nums[mid])
//             {
//                 case 0: swap(nums[low++], nums[mid++]); break;
                
//                 case 1: mid++; break;
                
//                 case 2: swap(nums[mid], nums[high--]); break;
//             }
//         }
//     }


int n = nums.lenght;
 for(i=0; i<n; i++){
    if(nums[i] <= 0 || nums[i] >n)
    nums[i] = n+1
 }

  for(i=0; i<n; i++){
    int id = Math.abs(nums[i]);
    if(id>n) continue;
    id--;
    if(nums[id]>0) nums[id] = -nums[id];
  }

   for(i=0; i<n; i++){
    if(nums[i]>0)
    return i + 1;
   }
   return n+1;
}
};
