#ifndef VARIATION2_H
#define VARIATION2_H
#include "time.h"
class Variation2
{
    public:
        Variation2();
        int** generateThreads(int rowsA, int colA, int rowsB, int colB);
        clock_t secondTime();
    protected:

    private:
};

#endif // VARIATION2_H
