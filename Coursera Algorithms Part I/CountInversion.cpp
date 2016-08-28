#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator IterType;
long long sortNCount(IterType begin, IterType end);
long long countSplitInv(IterType begin, IterType mid, IterType end);
vector<int> arr;
int main()
{
    ifstream ifs("IntegerArray.txt");
    int num;
    while (ifs >> num)
        arr.push_back(num);
    cout << sortNCount(arr.begin(), arr.end()) << endl;
    return 0;
}
long long sortNCount(IterType begin, IterType end)
{
    if (end - begin == 1)
        return 0;
    else {
        auto n = end - begin;
        auto half = (n + 1) / 2;
        IterType mid = begin + half;
        long long x = sortNCount(begin, mid);
        long long y = sortNCount(mid, end);
        long long z = countSplitInv(begin, mid, end);
        return x + y + z;
    }
}
long long countSplitInv(IterType begin, IterType mid, IterType end)
{
    vector<int> tempVec(begin, end);
    IterType i = begin, j = mid, k = tempVec.begin();
    long long count = 0;
    while (k != tempVec.end()) {
        if (i == mid)
            *k++ = *j++;
        else if (j == end)
            *k++ = *i++;
        else if (*i <= *j)
            *k++ = *i++;
        else {
            count += mid - i;
            *k++ = *j++;
        }
    }
    copy(tempVec.cbegin(), tempVec.cend(), begin);
    return count;
}