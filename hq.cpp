#include <iostream>
#include <vector>
#include <random>
#include <chrono>

// low = start index
// high - end index
int hoaresPartition(std::vector<int>&arr,int low, int high)
{
    //choose pivot, hoares uses first element
    int pivot = arr[low];

    //pointers
    int i = low - 1;
    int j = high + 1;

    while(true)
    {
        //move left pointer, stop when element > pivot:
        do{
            i++;

        }while(arr[i] < pivot);

        // move right pointer, stop when element <= pivot:
        do{
            j--;

        }while(arr[j] > pivot);

        //check if done, returns parition index:
        if(i >= j)
            return j;
        
        // swap:
        std::swap(arr[i],arr[j]);
    }
}
int LomutoPartitioning(std::vector<int>&A, int p, int r)
{
    int pivot = A[r];
    int i = p - 1;
    for(int j = p; j < r; j = j + 1)
    {
        if(A[j] <= pivot)
        {
            i = i + 1;
            int temp_1 = A[i];
            A[i] = A[j];
            A[j] = temp_1;
        }
    }
    int temp_2 = A[i+1];
    A[i+1] = A[r];
    A[r] = temp_2;
    int result = i + 1;
    return result;
}

void Hoaresquicksort(std::vector<int>&arr, int low, int high)
{
    if(low < high)
    {
        int p = hoaresPartition(arr,low,high);

        Hoaresquicksort(arr,low,p);
        Hoaresquicksort(arr,p+1,high);
    }
}

void LomutoQuickSort(std::vector<int> & A, int p, int r)
{
    if(p < r)
    {
        int q;
        q = LomutoPartitioning(A, p, r);
        LomutoQuickSort(A, p, q-1);
        LomutoQuickSort(A, q+1, r);
    }
}

std::vector<int>repeatingArray(int size, int min, int max)
 {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<>rn(min, max);

    std::vector<int>repeatingArray(size);

    for (int i = 0; i<size;i++)
        repeatingArray[i] = rn(gen);

    return repeatingArray;
}

std::vector<int>sortedArray(int size)
{
    std::vector<int>A(size);

    for(int i = 0; i < size; i++)
    {
        A[i] = i;
    }
    return A;
}

std::vector<int> randomArray(int size)
{
    std::vector<int>array(size);

    for(int i = 0; i < size; i++)
        array[i] = rand() % 100;

    return array;
}

std::vector<int>generateReverseSortedArray(int size)
{
    std::vector<int>A(size);

    for(int i = 0; i < size; i++)
        A[i] = size - i; 
    
    return A;
}

void HoaresTestRepeating(int size)
{
    /// REPEATING ARRAY TEST//
    std::vector<int>repeatArr = repeatingArray(size,1,5);

    auto start = std::chrono::high_resolution_clock::now();

    Hoaresquicksort(repeatArr,0,repeatArr.size()-1);
    ///////

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Repeating Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";
}

void LomutoTestRepeating(int size)
{
    /// REPEATING ARRAY TEST//
    std::vector<int>repeatArr = repeatingArray(size,1,5);

    auto start = std::chrono::high_resolution_clock::now();

    LomutoQuickSort(repeatArr,0,repeatArr.size()-1);
    ///////

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Repeating Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

}

void HoaresTestSorted(int size)
{
    // SORTED ARRAY TEST//
    std::vector<int>sortedArr = sortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    Hoaresquicksort(sortedArr,0,sortedArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

void LomutoTestSorted(int size)
{
    // SORTED ARRAY TEST//
    std::vector<int>sortedArr = sortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    LomutoQuickSort(sortedArr,0,sortedArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

void HoarsTestReverse(int size)
{
    // REVERSE SORTED ARRAY TEST//
    std::vector<int>reverseArr = generateReverseSortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    Hoaresquicksort(reverseArr,0,reverseArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Reverse Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

void LomutoTestReverse(int size)
{
        // REVERSE SORTED ARRAY TEST//
    std::vector<int>reverseArr = generateReverseSortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    LomutoQuickSort(reverseArr,0,reverseArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Reverse Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

void HoaresTestRandom(int size)
{
    // RANDOM ARRAY TEST//
    std::vector<int>randomArr = randomArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    Hoaresquicksort(randomArr,0,randomArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Random Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

void LomutoTestRandom(int size)
{
    // RANDOM ARRAY TEST//
    std::vector<int>randomArr = randomArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    LomutoQuickSort(randomArr,0,randomArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Random Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}

//partition function for quicksort
int randomLomuto(std::vector<int> &A, int low, int high)
{
    int pivot = A[high];                  //choose the last element as pivot
    int i = low - 1;                        //index of smaller element 

    for(int j = low; j < high; j++){        //traverse through all elements
        if(A[j] < pivot){                 //if the current element is smaller than pivot
            i++;                            //increment index of smaller element
            std::swap(A[i], A[j]);           //swap the elements
        }
    }
    std::swap(A[i + 1], A[high]);          
    return i + 1;
}

//Pick a random pivot
void randomize(std::vector<int> &A, int low, int high){
    int randomIndex = low + rand() % (high - low + 1);  //pick a random index between low and high
    std::swap(A[randomIndex], A[high]);                  //swap the random pivot with the last element
}

// QuickSort function
void RandomLomutoQuickSort(std::vector<int> &A, int low, int high){
    if(low < high){                             //check if the array has more than one element
        randomize(A, low, high);              //randomize the pivot
        int pi = randomLomuto(A, low, high);        //partition the array around the pivot

        RandomLomutoQuickSort(A, low, pi - 1);            //Recursive calls to sort elements on left
        RandomLomutoQuickSort(A, pi + 1, high);           //Recursive calls to sort elements on right
    }
}

void RandomLomutoTestSorted(int size)
{
    // SORTED ARRAY TEST//
    std::vector<int>sortedArr = sortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    RandomLomutoQuickSort(sortedArr,0,sortedArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////

}
void RandomLomutoTestReverse(int size)
{
    // REVERSE SORTED ARRAY TEST//
    std::vector<int>reverseArr = generateReverseSortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    RandomLomutoQuickSort(reverseArr,0,reverseArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Reverse Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}
void RandomLomutoTestRandom(int size)
{
    // RANDOM ARRAY TEST//
    std::vector<int>randomArr = randomArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    RandomLomutoQuickSort(randomArr,0,randomArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Random Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}
void RandomLomutoTestRepeating(int size)
{
    /// REPEATING ARRAY TEST//
    std::vector<int>repeatArr = repeatingArray(size,1,5);

    auto start = std::chrono::high_resolution_clock::now();

    RandomLomutoQuickSort(repeatArr,0,repeatArr.size()-1);
    ///////

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Repeating Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

}


int RandomHoaresPartition(std::vector<int>& arr, int low, int high){
    int randIndex = low + rand() % (high - low +1);//random pivot
    std::swap(arr[low], arr[randIndex]);

    int pivot = arr[low]; //now the pivot is random
    int i = low - 1;
    int j = high + 1;
    while(1){
        do{ i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if(i >= j) return j;
        std::swap(arr[i],arr[j]);
    }
}

void randomHoaresQuicksort(std::vector<int>& arr, int low, int high){
    //base condition
    if (low >=  high){
        return;
    }
    //rearrange elements according to pivot
    int pivot  = RandomHoaresPartition(arr, low, high);
    //recur on subarrays 
    randomHoaresQuicksort(arr, low, pivot);
    randomHoaresQuicksort(arr, pivot+1, high);
}

void RandomHoaresTestSorted(int size)
{
    // SORTED ARRAY TEST//
    std::vector<int>sortedArr = sortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    randomHoaresQuicksort(sortedArr,0,sortedArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}
void RandomHoaresTestReverse(int size)
{
    // REVERSE SORTED ARRAY TEST//
    std::vector<int>reverseArr = generateReverseSortedArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    randomHoaresQuicksort(reverseArr,0,reverseArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Reverse Sorted Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}
void RandomHoaresTestRandom(int size)
{
    // RANDOM ARRAY TEST//
    std::vector<int>randomArr = randomArray(size);

    auto start = std::chrono::high_resolution_clock::now();

    randomHoaresQuicksort(randomArr,0,randomArr.size()-1);

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Random Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

    //////////
}
void RandomHoaresTestRepeating(int size)
{
    /// REPEATING ARRAY TEST//
    std::vector<int>repeatArr = repeatingArray(size,1,5);

    auto start = std::chrono::high_resolution_clock::now();

    randomHoaresQuicksort(repeatArr,0,repeatArr.size()-1);
    ///////

    //Timing:
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Repeating Array Execution time: " << elapsed.count() << " microseconds\n";
    std::cout << "-----------------------------------------------------------------------\n";

}