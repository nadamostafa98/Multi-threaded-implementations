#include "mergeSort.h"
#include "pthread.h"
#include "Reading.h"
#include <iostream>

using namespace std;

mergeSort::mergeSort(){

}
void* sorting(void* arg){   //merge sort algorithm
    mergeSort::parameters* p = (mergeSort::parameters*)arg;     //a struct to make sure to receive the right parameters for each thread
    int left = p -> l;
    int right = p -> r;

    if(left < right){
    int mid = left + (right - left) / 2;
    int* a = p -> arr;
    pthread_t threads[2];

    mergeSort::parameters* p2 = new mergeSort::parameters();    //create a struct of elements of the first thread
    p2 -> l = left;
    p2 -> r = mid;
    p2 -> arr = a;

    mergeSort::parameters* p3 = new mergeSort::parameters();    //create a struct for elements of the second thread
    p3 -> l = mid + 1;
    p3 -> r = right;
    p3 -> arr = a;

    pthread_create(&threads[0], NULL,sorting, (void*)(p2));     //recursively call the sorting function on the first half in a new thread
    pthread_create(&threads[1], NULL,sorting, (void*)(p3));     //recursively call the sorting function on the second half in a new thread
                                    //join the created threads
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    mergeSort().merging(p);
    }

}
mergeSort::mergeSort(int* a, int left, int right)   //constructor for the mergeSort class to take the input parameters and pass them to the sorting function
{
    mergeSort::parameters* p = new mergeSort::parameters();
    p -> l = left;
    p -> r = right;
    p -> arr = a;
    sorting((void*)(p));
}

void mergeSort::merging(void* arg){         //merging the elements while sorting them
    mergeSort::parameters* p = (mergeSort::parameters*)arg;     //a struct containg the elements of each merge to make sure that no thread takes the wrong parameters
    int left = p ->l;
    int right = p ->r;
    int* arr = p ->arr;
    int mid = left + (right - left) / 2;
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int array1[len1];
    int array2[len2];
    for(int i = 0; i < len1; i++){
        array1[i] = arr[i + left];
    }
    for(int j = 0; j < len2; j++){
        array2[j] = arr[j + mid + 1];
    }
    int i = 0, k = left, j = 0;
    while(i < len1 && j < len2){
        if(array1[i] <= array2[j]){
            arr[k++] = array1[i++];
        }
        else{
            arr[k++] = array2[j++];
        }
    }
    while(i < len1){
        arr[k++] = array1[i++];
    }
    while( j < len2){
        arr[k++] = array2[j++];
    }
}
