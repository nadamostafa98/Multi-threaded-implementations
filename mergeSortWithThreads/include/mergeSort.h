#ifndef MERGESORT_H
#define MERGESORT_H


class mergeSort
{
    public:
        mergeSort();
        mergeSort(int* a, int left, int right);
        struct parameters{
            int l;
            int r;
            int* arr;
        };
        void merging(void* arg);
    protected:

    private:
};

#endif // MERGESORT_H
