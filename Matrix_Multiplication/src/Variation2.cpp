#include "Variation2.h"
#include "read.h"
#include "pthread.h"
#include <iostream>
#include "time.h"
using namespace std;

Variation2::Variation2()
{
}

clock_t time2;      //variable to save the time taken
int cCol = 0;       //number of col in C
int cRows = 0;      //number of rows in C
int counterI = 0;   //counter to know which row I am in on the output array
int counterJ = 0;   //counter to know which column I am in on the output array
int aCol = 0;       //number of col in A
int bCol = 0;       //number of col in B
int bRows = 0;      //number of rows in B
int aRows = 0;      //number of rows in A
int** C2;
read r2;

struct st{  //struct to save the current row and col for each thread
    int x;
    int y;
};

void* multiply2(void* arg){ //function to multiply each element in the output array
    st* ss=(st*)arg;        //get elements of the thread from the struct
    int i =  ss->x;
    int j = ss->y;
    for(int k = 0; k < aCol; k++){
        C2[i][j] += r2.A[i][k] * r2.B[k][j];
    }
}

int** Variation2::generateThreads( int rowsA, int colA, int rowsB, int colB){       //function to generate a thread for the multiplication procedure of each element in the output array
    cRows = rowsA;
    cCol = colB;
    aCol = colA;
    bCol = colB;
    bRows = rowsB;
    aRows = rowsA;

    C2 = new int* [cRows];      //output matrix
    for(int i = 0; i < cRows; i++){
        C2[i] = new int[cCol];
    }
    time2 = clock();        //starting time
    pthread_t threads[cRows * cCol];
    for(int i = 0; i < cRows * cCol; i++){
        st* ss = new st();      //saving the current row n column of each thread
        ss -> x = counterI;
        ss -> y = counterJ;
        pthread_create(&threads[i], NULL, multiply2, (void*)(ss));  //generating a thread for each element
        if(counterJ == cCol - 1){
            counterJ = 0;
            counterI++;
        }
        else{
            counterJ++;
        }
    }
    for(int i = 0; i < cRows * cCol; i++){
        pthread_join(threads[i], NULL);     //joining the threads
    }
    time2 = clock() - time2;        //calculating total time taken
    return C2;

}
clock_t Variation2::secondTime(){
    return time2;
}
