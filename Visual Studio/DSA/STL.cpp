#include<bits/stdc++.h>
using namespace std;
#include<vector>
/*
void print(){
    cout<<"Pulkit";
} 
int Sum(int a, int b){
    return(a + b);
}

int main(){
//print();

int s = Sum(1, 5);
cout<<s;
return 0;
}
*/
/*
void vector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
}

vector<int>::iterator it v.begin();
i++;
cout << *(it)
*/

/*
//print user given integer value 
int main(){
 
 int num;
 cout<<"enter the number: ";
 cin>>num;
 cout<<"the entered number is: "<<num<<endl;
 
 return 0;
}
*/

/*
//Add up two intger 
int main(){
    int num1, num2, sum;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the secound number: ";
    cin>>num2;

    sum = (num1 + num2);
    cout<<"total is: "<<sum<<endl;

    return 0;
}
*/

/*
//divisor and divident
int main(){
    int divisor, dividend, quotient, remainder;
    cout<<"Enter the dividend: ";
    cin>>dividend;
    cout<<"Enter the divisor: ";
    cin>>divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout<<"Quotient: "<<quotient<<endl;
    cout<<"Remainder: "<<remainder;

    return 0;
}
*/

/*
//Swapping two numbers 
int main(){
    int a, b, temp;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Before Swapping."<<endl;
    cout<<"a: "<<a<<"\nb: "<<b<<endl;

    temp = a;
    a = b;
    b = temp;

    cout<<"\nAfter swapping"<<endl;
    cout<<"a: "<<a<<"\nb: "<<b<<endl;
}
*/

/*
//program to find ASCII value 
int main(){
    char c;
    cout<<"Enter char: ";
    cin>>c;
    cout<<" ASCII value "<< c <<" is "<<int(c);
    return 0;
}
*/

/*
//Even or odd
int main(){
    int n;
    cout<<"Enter the integer: ";
    cin>>n;

    if (n%2 == 0){
        cout<<"No is even.";
    }
    else {
        cout<<"No is odd.";
    }

    return 0;
}
*/

/*
//Largest numbers
int main(){
    float n1, n2, n3;
    cout<<"Enter three nos: ";
    cin>>n1>>n2>>n3;

    if((n1>=n2) && (n1>n3)){
        cout<<"largest number "<<n1;
    }
    else if( (n2>=n1) && (n2>=n3)){
        cout<<"largest number "<<n2;
    }
    else {
        cout<<"largest number"<<n3;
    }

    return 0;
}
*/ 

//Roots of quadratic equations  ---> to be done 

/*
//Sum of first n natural numbers 
int main(){
    int n, sum = 0;
    cout<<"Enter the positive number ";
    cin>>n;
    for(int i=1; i<=n; ++i){
        sum += i;
    }
    cout<<"sum "<<sum;
    
    return 0;
}
*/

/*
//leap year 
int main() {
int year;
cout << "Enter a year: ";
cin >> year;
if (year % 4 == 0) {
if (year % 100 == 0) {
if (year % 400 == 0)
cout << year << " is a leap year.";
else
cout << year << " is not a leap year.";
}
else
cout << year << " is a leap year.";
}
else
cout << year << " is not a leap year.";

return 0;
}
*/


/*

// Vector 
int main(){
    vector<int> v;
    cout<<"Capacity->"<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity->"<<v.capacity()<<endl;
    
    v.push_back(2);
    cout<<"Capacity->"<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity->"<<v.capacity()<<endl;
    
    cout<<"Element at secound index->"<<v.at(0)<<endl;   
    
    cout<<"First element"<<v.front()<<endl;
    cout<<"last element"<<v.back()<<endl;

    cout<<"before pop"<<endl;
    for (int i:v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();
     
    cout<<"After pop"<<endl;
    for (int i:v){
        cout<<i<<" ";
    }
}
*/

/*
// Deque 
int main(){

  deque<int> d;
  d.push_back(3);
  d.push_front(2);

  for (int i:d){
    cout<<i<<" ";
  }

  //d.pop_front();
  cout<<endl;
  cout<<"Element at first index->"<<d.at(1)<<endl;
  cout<<"Empty or not"<<d.empty()<<endl;
  cout<<"before erase"<<d.size()<<endl;
  d.erase(d.begin(), d.begin()+1);
  cout<<"after erase"<<d.size()<<endl;
   
   for( int i:d){
   cout<<i<<" ";
  }
}
*/

/*

//Lists
int main(){
    list<int> l;

    l.push_back(1);
    l.push_front(2);

    for (int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i : l){
        cout<<i<<" ";
    }
 
 cout<<"size if llst"<<l.size()<<endl;

}

*/

/*
//Stack 
int main(){
    stack<string> s;

    s.push("Pulkit");
    s.push("kumar");
    s.push("Giddu");

    cout<<"Top Element "<<s.top()<<endl;
    cout<<"Size of stack "<<s.size()<<endl;
    cout<<"Empty or not "<<s.empty()<<endl;
}
*/

/*
//Priority Queue
int main(){
    //max heap
    priority_queue<int> max;

    //min heap
    priority_queue<int, vector<int> , greater<int>> min;

    max.push(2);
    max.push(1);
    max.push(3);
    max.push(0);

    int n = max.size();
    for (int i=0; i<n; i++){
        cout<<max.top()<<" ";
        max.pop();
    }cout<<endl;

    min.push(4);
    min.push(2);
    min.push(1);
    min.push(0);
    min.push(3);
    min.push(5);

    int m = min.size();
    for (int i = 0; i<m; i++ ){
        cout<<min.top()<<" ";
        min.pop();
    }cout<<endl;
}
*/

//Sets
int main(){
    set<int> s;
    s.insert(0); 
    s.insert(2); 
    s.insert(3); 
    s.insert(1); 
    s.insert(4);

    for (auto i:s){
        cout<<i<<" ";
    } cout<<endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
     for (auto i:s){
        cout<<i<<" ";
    } cout<<endl;

    cout<<" 5 is present or not "<<s.count(4)<<endl;

}


//Maps is a datastructure in which it stores values in unique key
//Do it later while covering the topic