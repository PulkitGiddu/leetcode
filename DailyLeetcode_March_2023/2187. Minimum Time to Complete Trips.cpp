2187. Minimum Time to Complete Trips 

Code: 
class Solution {
public:
    long long int numberOfTripsForGivenTime(vector<int>& a, long long int givenTime) {
        long long totalTrips = 0; 
        for(auto x: a){
            // so first convert the val to long long int

            long long int val = x; 

            totalTrips += (givenTime/val);  
        }
        return totalTrips;
        
    }

    long long minimumTime(vector<int> & arr, int totalTrips){
        long long int lowestTime = 1; 
        long long int highestTime = 1e14; 
        while(lowestTime < highestTime){
            // apply B.S binary search 
            long long int mid = lowestTime + (highestTime - lowestTime)/ 2;

            if(numberOfTripsForGivenTime(arr, mid) >= totalTrips)
            highestTime = mid; 
            else
            lowestTime = mid+1;
        }
        return lowestTime;
    }
};
