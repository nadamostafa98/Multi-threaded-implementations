#ifndef VARIATION1_H
#define VARIATION1_H
#include <time.h>

class Variation1
{
    public:
        Variation1();
        int** generateThreads(int rowsA, int colA, int rowsB, int colB);
        clock_t firstTime();
    protected:

    private:
};

#endif // VARIATION1_H
