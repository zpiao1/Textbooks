#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int num;
    int sum = 0;
    ifstream ifs("Median.txt");
    priority_queue<int, vector<int>, greater<int>> hHigh; // stores the maximum half
    priority_queue<int> hLow;   // stores the minimum half
    int first, second;
    ifs >> first >> second; // first = 6331, second = 2793
    hHigh.push(first);
    hLow.push(second);
    sum = (first + second) % 10000;
    while (ifs >> num) {
        if (num < hLow.top())   // Lower than the maximum of the lower half
            hLow.push(num);     // insert into the lower half
        else
            hHigh.push(num);    // Higher than the maximum of the lower half, insert into the higher half
        if (hLow.size() - hHigh.size() == 2) {  // Rebalance
            hHigh.push(hLow.top());
            hLow.pop();
        }
        else if (hHigh.size() - hLow.size() == 2) {
            hLow.push(hHigh.top());
            hHigh.pop();
        }
        sum += hHigh.size() > hLow.size() ? hHigh.top() : hLow.top();
        sum %= 10000;
    }
    cout << sum << endl;
    return 0;
}