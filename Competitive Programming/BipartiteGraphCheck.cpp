#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vii AdjList;
int main() {
    // inside int main()
    queue<int> q;
    q.push(s);
    vi color(V, INF);
    color[s] = 0;
    bool isBipartite = true;    // addition of one boolean flag, initially true
    while (!q.empty() && isBipartite) { // similar to the original BFS routine
        int u = q.front();
        q.pop();
        for (const auto &v : AdjList[u]) {
            if (color[v.first] == INF) {    // but, instead of recording distance,
                color[v.first] = 1 - color[u];  // we just record two colors {0, 1}
                q.push(v.first);
            } else if (color[v.first] == color[u]) {    // u & v.first has the same color
                isBipartite = false;
                break;  // we have a coloring conflict
            }
        }
    }
    return 0;
}