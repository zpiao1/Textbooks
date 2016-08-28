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
    auto i = begin + 1, j = begin + 1;
    temp = *(end - 1);
    *(end - 1) = *begin;
    *begin = temp;
    auto pivot = begin;
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