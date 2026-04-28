#include <iostream>
#include <chrono>
#include "hq.h"

int main(int argc, char *argv[])
{
    int size;
    std::cin >> size;

    //HOARES PARTITION TEST:
    
    HoaresTestSorted(size);
    HoaresTestReverse(size);
    HoaresTestRandom(size);
    HoaresTestRepeating(size);
    
    //LOMUTOS PARTITION TEST:
    LomutoTestSorted(size);
    LomutoTestReverse(size);
    LomutoTestRandom(size);
    LomutoTestRepeating(size);

    // RANDOM LOMUTOS TEST:
    RandomLomutoTestSorted(size);
    RandomLomutoTestReverse(size);
    RandomLomutoTestRandom(size);
    RandomLomutoTestRepeating(size);

    //RANDOM HOARES TEST:
    RandomHoaresTestSorted(size);
    RandomHoaresTestReverse(size);
    RandomHoaresTestRandom(size);
    RandomHoaresTestRepeating(size);

    
    //Dual pivot quicksort tests:
    dualPivotSortedTest(size);
    dualPivotReverseSortedTest(size);
    dualPivotRandomTest(size);
    dualPivotRepeatingTest(size);


    return 0;
    
}
