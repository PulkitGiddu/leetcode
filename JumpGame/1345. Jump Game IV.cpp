1345. Jump Game IV
 
Code: 
class Solution{
    public:
    int minJumps(vector<int>& arr){
        int n = arr.size(); 

        unordered_map<int, vector<int>> indicesOfValue;

        for(int i = 0; i<n; i++)
        indicesOfValue[arr[i]].push_back(i);

        vector<bool> visited(n); visited[0] = true;

        queue<int> q; 
        q.push(0);

        int steps = 0; 

        while(!q.empty()){
            for(int size = q.size(); size > 0; --size){
                int i = q.front(); 
                q.pop();

                if(i == n-1) return steps;
                vector<int>& next = indicesOfValue[arr[i]]; 
                next.push_back(i-1); next.push_back(i+1); 

                for(int j : next){
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                    
                indicesOfValue[arr[i]].clear(); // avoid later lookup indicesOfValue arr[i]
            }
            steps++;
        }
        return 0;
    } 
};

Code2:

/*
Intuition of this Problem:
The problem requires us to find the minimum number of steps needed to reach the last index of a given array of integers. Each step can be one of the following:

Move one step forward to the next index (i+1) if it exists.
Move one step backward to the previous index (i-1) if it exists.
Move to any index j where the element at index i is equal to the element at index j (i.e., arr[i] == arr[j]).
Below diagram is based on above 3 conditions
WhatsApp Image 2023-03-05 at 7.05.43 AM.jpeg

We can use a BFS (breadth-first search) approach to find the minimum number of steps to reach the last index. Starting from the first index, we can visit all the neighboring indices and add them to a queue. We can then repeat this process for all the indices in the queue until we reach the last index.

To efficiently find the neighboring indices, we can use an unordered_map to store the indices of each value in the input array. This allows us to easily find the neighboring indices of a given index using the values at that index. We can mark the visited indices to avoid visiting them again and keep track of the number of steps taken to reach each index.

Once we reach the last index, we can return the number of steps taken to reach it. If we cannot reach the last index, we can return -1 to indicate that it is not possible to reach the last index.

Approach for this Problem:
Create an unordered_map called indices to store the indices of each value in the input array.
For each value in the input array, add its index to the corresponding vector in the indices map.
Create a queue called storeIndex to store the indices of adjacent elements and a vector called visited to mark visited indices.
Push the first index of the array to the storeIndex queue and mark it as visited in the visited vector.
Initialize a steps variable to 0.
While the storeIndex queue is not empty, do the following:
a. Get the size of the storeIndex queue.
b. For each index in the storeIndex queue, do the following:
i. If the index is the last index of the array, return the number of steps.
ii. Get the vector of indices for the current value from the indices map.
iii. Add the indices of the adjacent elements to the vector.
iv. For each index in the vector, if it is within the array bounds and has not been visited, push it to the storeIndex queue and mark it as visited in the visited vector.
v. Clear the vector of indices.
c. Increment the steps variable.
If the last index of the array is not reached, return -1.
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) 
            return 0;
        
        //After doing below three statements our unordered_map looks like this
        //it will store value and vector<int> will store indices of that value    
            //-23: [1, 2],
            //3: [8],
            //23: [5, 6, 7],
            //100: [0, 4],
            //404: [3, 9] 

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        //queue will store index of adjacent element
        queue<int> storeIndex;
        //visited will take care wheather the particular index is visited or not
        vector<bool> visited(n);
        storeIndex.push(0);
        visited[0] = true;
        int steps = 0;
        while (!storeIndex.empty()) {
            int size = storeIndex.size();
            while (size--) {
                int currIndex = storeIndex.front();
                storeIndex.pop();
                //if currIndex == lastIndex of the array, it means we got the answer and we return the number of steps required to reach at the last index
                if (currIndex == n - 1) 
                    return steps;
                //below statement will store vector<int> from unordered_map, it means our it will take care of arr[i] == arr[j] && i != j condition
                vector<int>& jumpNextIndices = indices[arr[currIndex]];
                //below two statement take care of wheather next jump be i + 1 or i - 1
                jumpNextIndices.push_back(currIndex - 1);
                jumpNextIndices.push_back(currIndex + 1);
                for (int jumpNextIndex : jumpNextIndices) {
                    if (jumpNextIndex >= 0 && jumpNextIndex < n && !visited[jumpNextIndex]) {
                        storeIndex.push(jumpNextIndex);
                        visited[jumpNextIndex] = true;
                    }
                }
                //In the given code, jumpNextIndices is used to store the indices of the same value as the current index, and also the indices to which we can jump from the current index (i.e. currIndex + 1 and currIndex - 1).
                //If we do not clear jumpNextIndices at the end of each iteration of the while loop, it will keep storing the indices for the same value and also the indices to which we can jump from the previous iterations as well, leading to incorrect results or time limit exceeded.
                //So, including the statement jumpNextIndices.clear(); at the end of each iteration of the while loop is important to make sure that the jumpNextIndices vector only contains the valid indices for the current iteration.
                jumpNextIndices.clear();
            }
            steps++;
        }
        return -1; // unreachable
    }
};
