// Painter Partititon Problem  Coding ninjas " https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557?leftPanelTab=0 "
/*

*/
Code: 
bool isPossible(vector<int> &boards, int k, int mid){
   int paintersCount = 1;
   int minimumTime = 0;
   for(int i=0; i<boards.size(); i++){
       if(minimumTime + boards[i] <= mid){
           minimumTime += boards[i];
       }
       else{
           paintersCount++;
           if(paintersCount > k || boards[i] > mid){
               return false;
           }
           minimumTime = boards[i];
       }
   }
   return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
   int start = 0;
   int sum = 0;
   for(int i=0; i<boards.size(); i++){
       sum += boards[i];
   }   
   int end = sum;
   int ans = -1;
   int mid = start + (end - start)/2;
   while(start <= end){
       if(isPossible(boards, k, mid)){
           ans = mid;
           end = mid-1;
       } 
       else{
           start = mid+1;
       }
       mid = start + (end - start)/2;
   }
   return ans;
}
