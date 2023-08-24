347. Top K Frequent Elements

Code  
// approch using min heap : where small element will be at top and we simply pop that element and get the most frequent element
class Soultion{
public: 
 vector<int> topKFrequent(vector<int>& nums, int k) {
   typedef pair<int, int > P; 
// Step1 : make an  map of all elements
   unordered_map<int, int> mp; 
   for(int &it:nums){
     mp[num]++;
   }

// Step 2: make the min Heap ( freq , value) order set kr do so that less freq element will go at top and we can pop that.
   prioroty_queue<P, vector<P>, greater<P>> pq; 
   for(auto &nums:mp){
     int value = it.first; 
     int freq  = it.second;
     pq.push({freq. value});

// step 3: if size > k, we will simply pop that element out
     if(pq.size() > k){
     pq.pop(); 
     }
   }

// Step 4 : returning the result 
   vector<int> result; 
   while(!pq.empty()){
     result.push_back(pq.top().second);
     pq.pop();
   }
   return result; 
 }
};
