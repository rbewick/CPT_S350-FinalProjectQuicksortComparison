#pragma once
#include <vector>
void randomize(std::vector<int> &A, int low, int high);
int hoaresPartition(std::vector<int>&arr,int low, int high);
void LomutoQuickSort(std::vector<int> & A, int p, int r);
void quicksort(std::vector<int>&arr, int low, int high);

std::vector<int>repeatingArray(int size, int min, int max);
std::vector<int>sortedArray(int size);
std::vector<int> randomArray(int size);
std::vector<int>generateReverseSortedArray(int size);

void HoaresTestRepeating(int size);
void HoaresTestSorted(int size);
void HoaresTestReverse(int size);
void HoaresTestRandom(int size);

void LomutoTestSorted(int size);
void LomutoTestReverse(int size);
void LomutoTestRandom(int size);
void LomutoTestRepeating(int size);

void RandomLomutoTestSorted(int size);
void RandomLomutoTestReverse(int size);
void RandomLomutoTestRandom(int size);
void RandomLomutoTestRepeating(int size);

int randomLomuto(std::vector<int> &A, int low, int high);
void RandomLomutoQuickSort(std::vector<int> &A, int low, int high);

int RandomHoaresPartition(std::vector<int>& arr, int low, int high);
void randomHoaresQuicksort(std::vector<int>& arr, int low, int high);

void RandomHoaresTestSorted(int size);
void RandomHoaresTestReverse(int size);
void RandomHoaresTestRandom(int size);
void RandomHoaresTestRepeating(int size);


