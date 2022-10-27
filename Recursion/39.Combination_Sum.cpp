Q - 39. Combination Sum 
Code: 
class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans,vector<int>     & output) {
      
        if (ind == arr.size()) 
        {
        if (target == 0) 
        {
            ans.push_back(output);
        }
        return;
        }
      // pick up the element 
        if (arr[ind] <= target) 
        {
            output.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, output);
            output.pop_back();
        }
        
        findCombination(ind + 1, target, arr, ans, output);
        }
 
    public:
      vector <vector<int>> combinationSum(vector <int> & candidates, int target) {
      vector <vector<int>> ans;
      vector <int> output;
      findCombination(0, target, candidates, ans, output);
      return ans;
    }
};

Code2: iterative solution
class Solution {
    void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; //backtrack
        if(currSum==target){
            ans.push_back(currComb); //store the solution and backtrack
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
            currComb.push_back(candidates[i]); //put 1 option into the combination
            currSum+=candidates[i];
            combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
            currSum-=candidates[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans);
        return ans;
    }
};
