#include <iostream>
#include "Reading.h"
#include "mergeSort.h"
using namespace std;

int main()
{
    cout << "Unsorted Array: " <<endl;
    Reading r;  //read the input array from the file
    for(int j = 0; j < r.len; j++){ //printing the input array before sorting
        cout << r.arr[j] << " ";
    }
    cout<< endl <<endl;
    if(r.len < 2){
        cout << "Array is already sorted " <<endl;
        return 0;
    }
    mergeSort m( r.arr,0, r.len - 1);   //call the mergeSort function and pass the initial parameters to it
    cout << "Sorted Array: " <<endl;
    for(int i = 0; i < r.len; i++){ //printing the output array
        cout << r.arr[i]<<" ";
    }
    cout<< endl;
    return 0;
}
