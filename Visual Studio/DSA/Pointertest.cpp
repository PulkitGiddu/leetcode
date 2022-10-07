/*
Ques--> ASCII value of A is 65 resulting into 97
Which is ASCII value of small ao this “a” gets stored in “ch”. 
So this “a” gets stored in “ch”. As for when “*ptr” is incremented by “ch”, it gives value 97+32=129.
output 129,a
*/ 
#include<iostream>
using namespace std;
int main(){
    int a = 32, *ptr = &a;
    char ch = 'A', &cho = ch;

    cho +=a;
    *ptr += ch;
    cout<< a <<", "<< ch <<endl;
    return 0;  
}