#include<iostream>
using namespace std;
int main(){

    int marks[] = {25, 45, 22, 99};

    int mathmarks[4];
    mathmarks[0] = 202;
    mathmarks[1] = 100;
    mathmarks[2] = 300; 
    mathmarks[3] = 250;

    cout<<"These are math marks"<<endl;
    cout<<mathmarks[0]<<endl;
    cout<<mathmarks[1]<<endl;
    cout<<mathmarks[2]<<endl;
    cout<<mathmarks[3]<<endl;

    for (int i = 0; i<4; i++ ){
        cout<<"the value of marks "<<i<<marks[i]<<endl;
    }
      

    
    


    return 0;
}

// #include<iostream>
// using namespace std;
// int main(){
//     int sum  = 2;
//     cout<<"hello world"<<sum<<endl;
//     cout<<"hello world";
//     return 0;
// }