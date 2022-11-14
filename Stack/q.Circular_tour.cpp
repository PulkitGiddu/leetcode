Q - Circular tour 

Code: 
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0; // kami hamrey pass kitni hai 
       int balance = 0;
       int start = 0;
       
       for(int i = 0; i<n; i++){
           // left out balance we have after total petrol - total distance 
           balance += p[i].petrol - p[i].distance; 
       
        if(balance < 0){
            deficit += balance; 
            start = i+1; 
            balance = 0;
        }   
    }
        // augar kami + balance bada ho 0 sae then return the s pointer as it is reached.
        if( deficit + balance >= 0 ){
           return start;
        }
       else{
          return -1;
        }
    }
};
