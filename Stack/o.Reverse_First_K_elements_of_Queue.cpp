Q - Reverse First K elements of Queue 

Code: 
// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
   // step 1: fetch first k element form q and put it into stack 
   for(int i = 0; i<k; i++){
       int element = q.front();
       q.pop();
       s.push(element);
   }
   
   // step2: fetch element form stack and push it into queue
   while(!s.empty()) {
       int element = s.top();
       s.pop();
       q.push(element);
   }
   
   // step3: fetch first (n - k) from queue and push back 
   int t = q.size() - k;
   while(t-- ){
       int element = q.front();
       q.pop();
       q.push(element);
   }
   return q; 
   
}
