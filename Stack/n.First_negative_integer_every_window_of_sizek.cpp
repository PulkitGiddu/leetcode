Q - First negative integer in every window of size k 
Code: 

long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int> dq;
        vector<long long> ans;
        int negative = -1;
         
        //process first window
        for(int i=0; i<K; i++) {
            // current element is less then zero
            // store that index in my deque
            if(A[i] < 0) {
                dq.push_back(i);
            }
        }
         
        //push ans of FIRST window
        if(dq.size() > 0) { 
            ans.push_back(A[dq.front()]);
        }
         else
        {  // no element is present then 
            ans.push_back(0);
        }
         
        //now process for remaining windows
        for(int i = K; i<N; i++) {
             
            //first pop out of window element // removal
            if( !dq.empty() && (i - dq.front() ) >= K ) {
                                // current k size window mae nhi aatey toh remove krna padega 
                                // eska mtlb jo bhi chese yaha padi hai vo curr k size mae aati hai ya nhi 
                                // aati hogi toh keep it otherwise remove it 
                dq.pop_front();
            }
             
            // addition //then push current element
            if(A[i] < 0) // curr element is negative then push back element index into queue
                dq.push_back(i);
             
            // put into ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
 }
