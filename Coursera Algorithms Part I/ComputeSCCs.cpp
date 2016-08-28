#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;
#define VISITED 1
#define UNVISITED -1
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vi> G, Grev;
vi dfs_num;
vector<int> revorder, sizes, order;
vector<vi> lead;
stack<int> stk;
int leader;
void firstPass(int V);
void secondPass(int V);
void firstDFS(int node);
void secondDFS(int node);
int main()
{
	ifstream ifs("SCC.txt");
	int V;
	ifs >> V;
	int from, to;
	G.assign(V + 1, vi());
	Grev.assign(V + 1, vi());
	lead.assign(V + 1, vi());
	while (ifs >> from >> to) {
		G[from].push_back(to);
		Grev[to].push_back(from);
	}
	firstPass(V);
	secondPass(V);
	for (const auto &l : lead)
		sizes.push_back((int)l.size());
	sort(sizes.rbegin(), sizes.rend());
	for (int i = 0; i < 5; ++i) {
		cout << sizes[i]; 
		if (i != 4)
			cout << ',';
		else
			cout << endl;
	}
	return 0;
}
void firstPass(int V)
{
	dfs_num.assign(V + 1, UNVISITED);
	for (int node = V; node > 0; --node) {
		if (dfs_num[node] == UNVISITED) {
			leader = node;
			firstDFS(node);
		}
	}
}
void secondPass(int V)
{
	dfs_num.assign(V + 1, UNVISITED);
	order = vector<int>(revorder.rbegin(), revorder.rend());
	for (int node : order)
		if (dfs_num[node] == UNVISITED) {
			leader = node;
			secondDFS(node);
		}
}
void firstDFS(int node)
{
	dfs_num[node] = VISITED;
	stk.push(node);
	int curr;
	bool allexplored;
	while (!stk.empty()) {
		curr = stk.top();
		allexplored = true;
		for (int to : Grev[curr])
			if (dfs_num[to] == UNVISITED) {
				dfs_num[to] = VISITED;
				stk.push(to);
				allexplored = false;
				break;
			}
		if (allexplored) {
			revorder.push_back(curr);
			stk.pop();
		}
	}
}
void secondDFS(int node)
{
	dfs_num[node] = VISITED;
	stk.push(node);
	int curr;
	while (!stk.empty()) {
		curr = stk.top();
		stk.pop();
		for (int to : G[curr])
			if (dfs_num[to] == UNVISITED) {
				dfs_num[to] = VISITED;
				stk.push(to);
			}
		lead[leader].push_back(curr);
	}
}