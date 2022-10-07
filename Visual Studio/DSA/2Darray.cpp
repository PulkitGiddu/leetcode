#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][3], int target, int row, int col){
/*
When passing a two-dimensional array to a function, you must specify the number 
of columns as a constant when you write the parameter type, 
so the compiler can pre-calculate the memory addresses of individual elements.
*/

        for (int row =0; row<4; row++){
        for(int col = 0; col<3; col++){
            if(arr[row][col] == target){
                return 1;
            }
        }
    }
    return 0;
}

void printColSum(int arr[][3], int row, int col){

    cout << " Printing Sum - " << endl;
    for (int col =0; col<3; col++){
    int sum = 0;
        for(int row = 0; row<3; row++){
            sum += arr[col][row];
        }
        cout<< sum << " ";
    }

}

// to print row wise sum
void printSum(int arr[][3], int row, int col){

    cout << " Printing Sum - " << endl;
    for (int row =0; row<3; row++){
    int sum = 0;
        for(int col = 0; col<3; col++){
            sum += arr[row][col];
        }
        cout<< sum << " ";
    }

}

 int largestRowSum(int arr[][3], int row, int col){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int row =0; row<3; row++){
    int sum = 0;
        for(int col = 0; col<3; col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;

        }
    }
    cout<<" the maximum sum is "<< maxi << endl;
    return rowIndex;
 }

int main(){
//     // create 2D array 

//     // taking input - > row  wise input 
     int arr[3][3];
     cout<<"Enter the elements"<<endl;   
    for (int row =0; row<3; row++){
        for(int col = 0; col<3; col++){
            cin>>arr[row][col];
        }
        cout<< endl;
    }


// taking input for col wise

//  // i - rows
//  // j - Cols 
//     //     for (int col =0; col<4; col++){
//     //     for(int row = 0; row<3; row++){
//     //         cin>>arr[row][col];
//     //     }
//     // }

cout<<"Printing the array "<<endl; 
// // print 
    for (int row = 0; row<3; row++){
        for(int col = 0; col<3; col++){
            cout << arr[row][col] << " ";
        }
        cout<<endl;
    }

    /*out<<" Enter the element to search " << endl;
    int target; 
    cin >> target; 
    if(isPresent(arr, target , 3, 3)){
        cout<< " Element found " << endl;

    }
    else{
        cout<<"Not found"<<endl;
    }
    printColSum(arr, 3,3);
*/
int ansIndex = largestRowSum(arr, 3, 3);
cout<< " Max row is at index " << ansIndex << endl; 

    return 0;


}