#include <iostream>
#include <stdio.h>
#include "read.h"
#include "Variation1.h"
using namespace std;

int rA;
int rB;
int cA;
int cB;
read::read()
{
    freopen("matrices.txt","r",stdin);  //open input file
    cin>>rA>>cA;                //read the number of rows of A and number of columns of A
    A = new int*[rA];
    for(int i = 0; i < rA; i++){
        A[i] = new int[cA];
    }
    for(int i = 0; i < rA; i++){
        for(int j = 0; j < cA; j++){
            cin >> A[i][j];         //read each element in A
        }
    }
    cin >> rB >> cB;            //read the number of rows of B and number of columns of B
    B = new int* [rB];
    for(int i = 0; i < rB; i++){
        B[i] = new int[cB];
    }
    for(int i = 0; i < rB; i++){
        for(int j = 0; j < cB; j++){
            cin >> B[i][j];     //read each element in B
        }
    }
}
int read::rowsA(){
    return rA;
}
int read::rowsB(){
    return rB;
}
int read::colA(){
    return cA;
}
int read::colB(){
    return cB;
}
