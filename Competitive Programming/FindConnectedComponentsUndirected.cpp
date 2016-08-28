#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define VISITED 1
#define UNVISITED -1
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> AdjList;
vi dfs_num;
void dfs(int u) {
    dfs_num[u] = VISITED;
    for (const auto &v : AdjList[u])
        if (dfs_num[v.first] == UNVISITED) 
            dfs(v.first);
}
int main()
{
    // inside int main()---this is the DFS solution
    int numCC = 0;
    dfs_num.assign(V, UNVISITED);   // sets all vertices' state to UNVISITED
    for (int i = 0; i < V; ++i)     // for each vertex i in [0..V - 1]
        if (dfs_num[i] == UNVISITED) {
            printf("CC %d:", ++numCC);
            dfs(i);
            printf("\n");   // 3 lines here!
        }
    return 0;
}