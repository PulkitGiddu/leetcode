//Q - 1011 Capacity to ship packages in d days. 
/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/


/*
Intution:
-> Binary search can be applied not only on sorted array but also on monotonic(https://en.wikipedia.org/wiki/Monotonic_function) search space in which our answer lies.
-> If you are able to find the start and end of your search space which is monotonic in nature , you can start thinking of applying binary search on answers(search space) in a problem.
-> Here in this problem lets take the example of 2nd testcase:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6

-> Find the search space:

Think of a maximum weight ship can carry - This is the case if it has to carry all packages in a single day. It comes out to be total of all elements=16.
Think of a minimum weight ship can carry - This is the case if it has to carry single package everyday. So minimum weight comes out to be maximum of all elements=4.

So in weights = [3,2,2,4,1,4] our search space is from 4 to 16
If ship has capacity of 16 - Days taken 1
capacity of 4 - Days taken 5 -> (2,2) can be taken in a single day as capacity is 4

We can observe here that if we decrease the capacity of ship from 16 to 4, days taken will increase from 1 to 5.
Now here in the above case we have to find minimum capacity such that days taken is 3.

Apply simple binary search with low=4 and high=16 with a check functioin which tells us if it is possible to ship all the packages within given days with capacity=>mid= low+high/2.
Change low and high accordingly untill days =3 with minimum capacity.

class Solution {
public:
    bool helper(int mid,vector<int>& weights,int days){
        int count=1,sum=0;
        
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
            }
        }
        if(count<=days)
            return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0;
        int n=weights.size();
        
        for(int i=0;i<n;i++)
            maxCapacity+=weights[i];
        
        int low=*max_element(weights.begin(),weights.end()),high=maxCapacity;
        int result;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(mid,weights,days)){
                result=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return result;
    }
};
*/

Code: 
class Solution {
public: 
  bool ok(int mid, vector<int>&weights, int D){
  int n = weights.size();
    int days = 1;
    int total = 0;
    bool isValid = true;
    for(int i = 0; i<n; i++){
    if(weights[i] > mid)
      isValid = false;
      if(total + weights[i] <= mid)
        total += weights[i];
      else{
      days++;
        total = weights[i];  
        }
    }
  }
}

int shipWithinDays(vector<int>&weights, int D){
int l = 1;
  int r = 50000*500;
  int mid = l + (r - l)/2;
 while(l<r){
  if(ok(mid, weights, D))
    r = mid;
  else 
    l = mid + 1;
}
return l;
}
};










