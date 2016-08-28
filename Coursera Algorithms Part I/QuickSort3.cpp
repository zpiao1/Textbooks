#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
typedef vector<int>::iterator iterType;
void quickSort(iterType begin, iterType end, size_t &numComp);
vector<int> integers;
int main()
{
    ifstream ifs("QuickSort.txt");
    size_t numComp = 0;
    int i;
    while (ifs >> i) 
        integers.push_back(i);
    quickSort(integers.begin(), integers.end(), numComp);
    cout << numComp << endl;;
}
void quickSort(iterType begin, iterType end, size_t &numComp)
{
    auto n = end - begin;
    int temp;
    if (n <= 1)
        return;
    numComp += n - 1;
    auto mid = begin + ((n - 1) / 2);
    auto i = begin + 1, j = begin + 1;
    int min = (*begin > *mid ? *mid : *begin);
    int max = (*begin > *mid ? *begin : *mid);
    min = (min > *(end - 1) ? *(end - 1) : min);
    max = (max > *(end - 1) ? max : *(end - 1));
    iterType pivot;
    if (*begin != min && *begin != max)
        pivot = begin;
    else if (*mid != min && *mid != max)
        pivot = mid;
    else 
        pivot = end - 1;
    temp = *pivot;
    *pivot = *begin;
    *begin = temp;
    pivot = begin;
    while (j != end) {
        if (*j < *pivot) {
            temp = *j;
            *j = *i;
            *i = temp;
            i++;
        }
        j++;
    }
    temp = *(i - 1);
    *(i - 1) = *pivot;
    *pivot = temp;
    quickSort(begin, i - 1, numComp);
    quickSort(i, end, numComp);
}