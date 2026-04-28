// Citation: https://www.geeksforgeeks.org/dsa/dual-pivot-quicksort/

#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "hq.h"

using namespace std;
using namespace std::chrono;

int dualPivotPartitionFunction(vector<int> &A, int p, int r, int *pivotLeft)
{
    if(A[p] > A[r])
    {
        swap(A[p], A[r]);
    }

    int j = p + 1;
    int g = r - 1;
    int k = p + 1;
    int leftPivot = A[p];
    int rightPivot = A[r];

    while(k <= g)
    {
        if(A[k] < leftPivot)
        {
            swap(A[k], A[j]);
            j = j + 1;
        }
        else if(A[k] >= rightPivot)
        {
            while(A[g] > rightPivot && k < g)
            {
                g = g - 1;
            }
            swap(A[k], A[g]);
            g = g - 1;
            if(A[k] < leftPivot)
            {
                swap(A[k], A[j]); //!!!
                j = j + 1;
            }
        }
        k = k + 1;
    }
    j = j - 1;
    g = g + 1;

    swap(A[p], A[j]); // !!!
    swap(A[r], A[g]); // !!!

    *pivotLeft = j;

    return g;
}

void DualPivotQuickSort(vector<int> &A, int p, int r)
{

    if(p < r)
    {
        int pivotLeft;
        int pivotRight;
        pivotRight = dualPivotPartitionFunction(A, p, r, &pivotLeft);

        DualPivotQuickSort(A, p, pivotLeft-1);
        DualPivotQuickSort(A, pivotLeft + 1, pivotRight - 1);
        DualPivotQuickSort(A, pivotRight + 1, r);
    }

}



void dualPivotTestsAll()
{
    int max = 1000000;
    
    //Test:
    vector<int> B = {12, 34, 1, 2, 3, 4, 24, 8, 42, 75, 29, 77, 38, 57};
    DualPivotQuickSort(B, 0, B.size()-1);   
    for(int i = 0; i < B.size(); i++) 
    {
        cout << B[i] << " ";
    }

    
    cout << "Results Using DualPivotQuickSort With Lomuto Partitioning" << endl;

    cout << "Sorted Array Results: - - - - - - - - - - - - - - - - - - -" << endl;
    for(int i = 1; i <= max; i = i * 10)
    {
        int size = i;
        vector<int> A(size);
        sortedArray(size);
        vector<int> B = A;
        auto start = high_resolution_clock::now();
        DualPivotQuickSort(B, 0, B.size()-1);    
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: "<< duration.count() <<" microseconds" << endl << "Array Size: " << "items " << A.size() << endl << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;



    cout << "Reverse Sorted Array Results:  - - - - - - - - - - - - - - - - - - -" << endl;
    for(int i = 1; i <= max; i = i * 10)
    {
        int size = i;
        vector<int> A(size);
        generateReverseSortedArray(size);
        vector<int> B = A;
        auto start = high_resolution_clock::now();
        DualPivotQuickSort(B, 0, B.size()-1);    
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: "<< duration.count() <<" microseconds" << endl << "Array Size: " << "items " << A.size() << endl << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;

    
    cout << "Random Sorted Array Results:  - - - - - - - - - - - - - - - - - - -" << endl;
    for(int i = 1; i <= max; i = i * 10)
    {
        int size = i;
        vector<int> A = randomArray(size);
        vector<int> B = A;
        auto start = high_resolution_clock::now();
        DualPivotQuickSort(B, 0, B.size()-1);    
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: "<< duration.count() <<" microseconds" << endl << "Array Size: " << "items " << A.size() << endl << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
    
    cout << "Repeat Array Results:  - - - - - - - - - - - - - - - - - - -" << endl;
    for(int i = 1; i <= max; i = i * 10)
    {
        int size = i;
        vector<int> A = repeatingArray(size, 1, 5);
        //repeatArray(A, size);
        vector<int> B = A;
        auto start = high_resolution_clock::now();
        DualPivotQuickSort(B, 0, B.size()-1);    
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: "<< duration.count() <<" microseconds" << endl << "Array Size: " << "items " << A.size() << endl << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;

}
