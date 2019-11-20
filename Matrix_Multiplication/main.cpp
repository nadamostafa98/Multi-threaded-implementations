#include <iostream>
#include "Variation1.h"
#include "read.h"
#include "Variation2.h"
using namespace std;

int main()
{
   read h;      //reading from input file
   int rowsA = h.rowsA();
   int rowsB = h.rowsB();
   int colA = h.colA();
   int colB = h.colB();
   cout<< "Matrix A: "<<endl;       //printing matrix A
    for(int i = 0; i < rowsA; i++){
        for (int j = 0; j < colA; j++){
            cout<<h.A[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout<< "Matrix B: "<<endl;      //printing matrix B
     for(int i = 0; i < rowsB; i++){
        for (int j = 0; j < colB; j++){
            cout<<h.B[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    if(colA != rowsB){          //checking that the two matrices can be multiplied
        cout << "Invalid input!" << endl;
        return 0;
    }

   Variation1 v;
   Variation2 v2;
   int** C;
   int** C2;
   C = v.generateThreads(rowsA,colA,rowsB,colB);   // calculating A * B using a single thread for each row in the output C
   C2 = v2.generateThreads(rowsA,colA,rowsB,colB);  // calculating A * B using a single thread for each element in the output C
   cout<<"A * B using Variation a: "<<endl;     //printing C using the first variation (each element in a thread)
    for(int i = 0; i < rowsA; i++){
        for (int j = 0; j < colB ; j++){
            cout<<C2[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Time: "<<v2.secondTime()<<endl;  //printing the time taken in calculation using the first variation
    cout << endl;
    cout<<"A * B using Variation b: "<<endl;    //printing C using the second variation (each row in a thread)
    for(int i = 0; i < rowsA; i++){
        for (int j = 0; j < colB; j++){
            cout<<C[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Time: "<< v.firstTime()<<endl;   //printing the time taken in calculation using the second variation
    return 0;
}
