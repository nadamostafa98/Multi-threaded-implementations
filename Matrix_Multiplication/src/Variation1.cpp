#include "Variation1.h"
#include <iostream>
#include <pthread.h>
#include <time.h>
#include "read.h"
using namespace std;

Variation1::Variation1()
{
}

clock_t time1;      //variable to calculate the time used
int colC = 0;       //number of columns in C
int rowsC = 0;      //number of rows in C
int m = 0;          //colA and rowsB
int** C;
read r;

struct st{      //a struct to save the row number of each thread
    int x;
};

void* multiply(void* arg){      //multiplication function for each row in the output array seperately
    st* ss=(st*)arg;            //read from stuct the current row
    int i =  ss->x;
    for(int j = 0; j < colC; j++){
        for(int k = 0; k < m; k++){
            C[i][j] += r.A[i][k] * r.B[k][j];
        }
    }
}

int** Variation1::generateThreads( int rowsA, int colA, int rowsB, int colB){   //function that generates thread for each multiplication procedure of a rows
    rowsC = rowsA;
    colC = colB;
    m = colA;
    C = new int* [rowsC];       //output matrix
    for(int i = 0; i < rowsC; i++){
        C[i] = new int[colC];
    }
    time1 = clock();        //starting time
    pthread_t threads[rowsC];
    for(int i = 0; i <rowsC; i++){
         st* ss = new st();
         ss -> x = i;
        pthread_create(&threads[i], NULL, multiply, (void*)(ss));   //creating a new thread for each row
    }
    for(int i = 0; i<rowsC; i++){
        pthread_join(threads[i], NULL);     //joining all threads
    }
    time1 = clock() - time1;        //calculation the total time taken
    return C;

}
clock_t Variation1::firstTime(){
    return time1;
}
