#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi dfs_num;
vector<vii> AdjList;
vi ts;  // global vector to store the toposort in reverse order
#define VISITED 1
#define UNVISITED -1
void dfs2(int u) {  // different function name compared to original dfs
    dfs_num[u] = VISITED;
    for (const auto v : AdjList[u]) 
        if (dfs_num[v.first] == UNVISITED)
            dfs2(v.first);
    ts.push_back(u);    // that't it, this is the only change   
}
int main() {
    // inside int main()
    ts.clear();
    //memset(dfs_num, UNVISITED, sizeof dfs_num);
    dfs_num.assign(V, UNVISITED);
    for (int i = 0; i < V; ++i) // this part is the same as finding CCs
        if (dfs_num[i] == UNVISITED)
            dfs2(i);
    // alternative, call: reverse(ts.begin(), ts.end()); first
    for (int i = (int)ts.size() - 1; i >= 0; i--)   // read backwards
        printf(" %d", ts[i]);
    printf("\n");
    return 0;
}
/** Kahn's algorithm
enqueue vertices with zero incoming degree into a (priority) queue Q;
while (Q is not empty) {
    vertex u = Q.dequeue();
    put vertex u into a topological sort list;
    remove this vertex u and all outgoing edges from this vertex;
    if such removal causes vertex v to have zero incoming degree
        Q.enqueue(v);
}
*/
