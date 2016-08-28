#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <random>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef list<pair<int, list<int>>> TAdjList;
int minCut(TAdjList adjList);
int main()
{
    ifstream ifs("kargerMinCut.txt");
    int label;
    string line;
    TAdjList adjList;
    int min;
    while (getline(ifs, line)) {
        istringstream iss(line);
        int node;
        iss >> node;
        list<int> lst;
        while (iss >> label)
            lst.push_back(label);
        adjList.push_back({ node, lst });
    }
    min = minCut(adjList);
    for (int i = 0; i < 1000; ++i) {
        int a = minCut(adjList);
        min = min < a ? min : a;
    }
    cout << min << endl;
}
int minCut(TAdjList adjList)
{
    default_random_engine gen;
    size_t sz;
    srand(time(0));
    while ((sz = adjList.size()) > 2) {
        uniform_int_distribution<size_t> nodeDist(0, sz - 1);
        size_t nodepos;
        //nodepos = nodeDist(gen);
        nodepos = rand() % sz;
        auto iter = adjList.begin();
        for (size_t i = 0; i != nodepos; ++i)
            ++iter;
        int node = iter->first;
        //cout << "Node: " << node << endl;
        auto &lbls = iter->second;
        uniform_int_distribution<size_t> lblDist(0, lbls.size() - 1);
        //size_t labelpos = lblDist(gen);
        size_t labelpos = rand() % lbls.size();
        auto iter2 = lbls.begin();
        for (size_t i = 0; i != labelpos; ++i)
            ++iter2;
        int label = *iter2;
        //cout << "Label: " << label << endl;
        lbls.remove(label);
        adjList.remove_if([&label](const pair<int, list<int>> &p) {
            return p.first == label;
        });
        for (iter = adjList.begin(); iter != adjList.end(); ++iter)
            for (auto &c : iter->second)
                if (c == label) {
                    c = node;
                    lbls.push_back(iter->first);
                }
        lbls.remove(node);
    }
    return adjList.front().second.size();
}