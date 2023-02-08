904. Fruit Into Baskets 

Code: Concept of sliding window is used to solve this question
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0, res = 0;
        while(j < fruits.size())
        {
            mpp[fruits[j]]++;    
            if(mpp.size() <= 2) res = max(res, j-i+1);
            else
            {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res; 
    }
};


Code2: 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count; // hash map to store the frequency of the elements in the subarray
        int i, j; // variables i and j are used to keep track of the subarray boundaries
        for (i = 0, j = 0; j < fruits.size(); ++j) {
            count[fruits[j]]++; // increase the count of the current fruit
            if (count.size() > 2) { 
                if (--count[fruits[i]] == 0)count.erase(fruits[i]); // reduce the count of the first fruit and remove it from the map if its count becomes 0
                i++; // move the start of the subarray to the right
            }
        }
        return j - i; // return the length of the longest subarray with at most two unique elements
    }
};
