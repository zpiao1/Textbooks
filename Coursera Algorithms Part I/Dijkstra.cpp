#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <functional>
using namespace std;
int V = 200;
const int INF = 1000000;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> adjList;
vi dist(V + 1, INF);
class MinHeap {
public:
    MinHeap() = default;
    void push(int, int);
    void pop();
    ii front() { return heap.front(); }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
private:
    bool compare(const ii& ii1, const ii& ii2) {
        if (ii1.first != ii2.first)
            return ii1.first < ii2.first;
        else
            return ii1.second < ii2.second;
    }
    size_t parent(size_t pos) const {
        return (pos + 1) / 2 - 1;
    }
    size_t left(size_t pos) const {
        return (pos + 1) * 2 - 1;
    }
    size_t right(size_t pos) const {
        return (pos + 1) * 2;
    }
    void minHeapify(size_t pos);
    vector<ii> heap;
};
void MinHeap::push(int a, int b) {
    heap.push_back({ a, b });
    size_t pos = heap.size() - 1;
    while (pos != 0 && compare(heap[pos], heap[parent(pos)])) {
        swap(heap[pos], heap[parent(pos)]);
        pos = parent(pos);
    }
}
void MinHeap::pop() {
    if (heap.empty())
        return;
    heap.front() = heap.back();
    heap.pop_back();
    minHeapify(0);
}

void MinHeap::minHeapify(size_t pos) {
    size_t l, r, minPos;
    while (true) {
        l = left(pos);
        r = right(pos);
        if (l < heap.size() && compare(heap[l], heap[pos]))
            minPos = l;
        else
            minPos = pos;
        if (r < heap.size() && compare(heap[r], heap[minPos]))
            minPos = r;
        if (minPos == pos)
            break;
        swap(heap[pos], heap[minPos]);
        pos = minPos;
    }
}
int vertices[] = { 7,37,59,82,99,115,133,165,188,197 };
MinHeap pq;
int main()
{
    ifstream ifs("DijkstraData.txt");
    adjList.assign(V + 1, vii());
    int u, v, w;
    char comma;
    string line;
    istringstream iss;
    while (getline(ifs, line)) {
        iss.clear();
        iss.str(line);
        iss >> u;
        while (iss >> v >> comma >> w)
            adjList[u].push_back({ v, w });
    }
    dist[1] = 0;
    pq.push(0, 1);
    while (!pq.empty()) {
        ii front = pq.front();
        pq.pop();   // greedy: get shortest unvisited vertex
        int d = front.first;
        u = front.second;
        if (d > dist[u])    // incorrect pair
            continue;   // this is a very important check
        for (const auto &v : adjList[u])
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second; // relax operation
                pq.push(dist[v.first], v.first);
            }
    }
    for (int i = 0; i < 10; ++i) {
        if (i)
            cout << ',';
        cout << dist[vertices[i]];
    }
    cout << endl;
    return 0;
}