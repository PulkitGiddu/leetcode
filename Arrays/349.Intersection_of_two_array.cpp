//349. Intersection of two arrays 
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/
code: 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Sort both the arrays 
        sort(nums1.begin(), nums1.end());        
        sort(nums2.begin(), nums2.end());
        
        //check the lenght of both arrays
        int n = nums1.size();
        int m = nums2.size();
        
        //for storing unique values we have creted set 
        set<int> s;
        int i = 0, j = 0;
        while(i<n && j<m){
            // if i pointer is greater than j pointer move j++
            if(nums1[i] > nums2[j]) j++;
            // if i pointer is less than j pointer move i++  
            else if (nums1[i] < nums2[j]) i++;
            
            // or else if i == j store that value into set 
            else{
                s.insert(nums1[i]);
                    i++;
                    j++;
            }
        }
        
        // now we were storing our value into vector for only unique elements and returning our answer
        vector <int> ans;
        for (auto i : s)ans.push_back(i);
        return ans;

        
    }
};
