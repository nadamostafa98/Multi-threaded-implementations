#include "Reading.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Reading::Reading()
{
    freopen("array.txt", "r",stdin);    //read from input file
    cin >> len;                         //the first line is the array length
    arr = new int[len];
    int i = 0;
    while(i < len){
        cin >> arr[i];                  //reading the elements of the array and saving them
        i++;
    }
}
