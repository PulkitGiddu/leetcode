//****Q - 1781. Sum of Beauty of All Substrings
//improve 2nd approch.

/* 

*/
Code: 
 class Solution{
 public: 
   int beautySum(string s){
   int ans = 0;
     int n = s.size();
     for (int i = 0; i<n; i++){
     map<char, int> m;
       for(int j = i; j<n; j++){
       m[s[i]]++; // here storing frequency form i till j.. 
       int mf = 0;
         int lf = INT_MAX;
         for(auto a : m){
         mf = max(mf, a.second);
         ml = min(lf, a.second);
         }
          ans += mf - lf; 
         
       }
     } 
     return ans; 
   }
 };


Approch 2: we can think of using multiset concept here below code is exeding time limit. but i will  surely try to improve this question approch. 

// code:  
//  class Solution{
//  public: 
//    int beautySum(string s){
//    int ans = 0;
//      int n = s.size();
//      for (int i = 0; i<n; i++){
//      multiset<int> st;
//      map<char, int> m;
//        for(int j = i; j<n; j++){
//       if(m.find(s[j]) != m.end()){
//       st.erase(st.find(m[s[j]]));
//         m[s[j]]++;
//         st.insert(m[s[j]]);
        
//         ans += (*st.rbegin()-*st.begin());  
//        }
//      } 
//      return ans; 
//    }
//  };
 
