1523. Count Odd Numbers in an Interval Range 

Code: 
// we will calculate all odd number from 1 to low-1 and 1 to high;
// why low-1??
// because we want include our low value.

// Approach
// Total odd number between 1 and low - 1 is low/2.
// Total odd number between 1 and high is (high + 1 ) / 2.
// For getting answer we will do
// Total odd number between 1 and high - Total odd number between 1 and low - 1

1. 
  
class Solution {
public:
    int countOdds(int low, int high) {
 
        return ((high + 1) / 2) - (low / 2);
    }
};

2. 
  
class Solution{
    public: 
    int countOdds(int low, int high){
        if(low%2 == 0 && high%2==0){
            return((high-low)/2);
        }
        return (high - low) / 2 + 1;
    }
};
