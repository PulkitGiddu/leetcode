/*
Pointers in cpp -----> data type which holds the address of other data type
*/
#include<iostream>
using namespace std;
int main()

{
    int a = 3;
    int* b = &a;
    // & ---> (address of) opreator
    cout<<"The address of a is "<<&a<<endl;
    cout<<"The address of a is "<<b<<endl;
 
    // * ---> (value at) Derefrence opreator
    cout<<"the value at address b is "<<*b<<endl; 

    return 0;
}

//Ques ---> find output 

