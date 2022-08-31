//Relative sort array
/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/

code: 
class Solution {
public:
vector<int>relativeSortArray(vector<int>&arr1, vector<int>&arr2) {

    vector<int> v;
    int j; 
    for(int i=0;i<arr2.size();i++)
    {
        for(j=0;j<arr1.size();j++)
        {
            if(arr2[i]==arr1[j])
            {
                v.push_back(arr1[j]);   
                arr1[j]=-1;
            }
            
        }
    
    }
    sort(arr1.begin(),arr1.end());
     for(j=0;j<arr1.size();j++)
     {
         if(arr1[j]!=-1)
         {
             v.push_back(arr1[j]);
         }
     }
    
        return v;
}
};

