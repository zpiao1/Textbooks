#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int UNVISITED = -1;
const int VISITED = 1;
vi dfs_num; // global variable, initially all values are set to UNVISITED
vector<vii> AdjList;
void dfs(int u) {
    dfs_num[u] = VISITED;   // important: we mark this vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); ++j) {  // default DS: AdjList
        ii v = AdjList[u][j];   // v is a (neighbour, weight) pair
        if (dfs_num[v.first] == UNVISITED)  // important check to avoid cycle
            dfs(v.first);   // recursively visits unvisited neighbours of vertex u
    }
}
/**
void backtrack(state) {
    if (hit end state or invalid state) // we need terminating or
        return; // pruning condition to avoid cycling and to speed up search
    for each neighbor of this state     // try all permutation
        backtrack(neighbor);
}
*/
