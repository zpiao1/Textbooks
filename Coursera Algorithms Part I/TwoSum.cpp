#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ifstream ifs("algo1-programming_prob-2sum.txt");
    ofstream ofs("TwoSum.txt");
    unordered_set<long long> umll;
    long long num;
    while (ifs >> num)
        umll.insert(num);
    size_t ans = 0;
    for (long long t = -10000; t <= 10000; ++t)
        for (auto x : umll) {
            if (x == t - x)
                continue;
            if (umll.find(t - x) != umll.end()) {
                ++ans;
                ofs << x << "\t+\t" << (t - x) << "\t=\t" << t << endl;
                break;
            }
        }
    ofs << ans << endl;
    return 0;
}